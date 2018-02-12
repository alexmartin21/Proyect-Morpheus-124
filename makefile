#####################################################
CC=gcc
CFLAGS= -g -Wall -pedantic -ansi
MODULOS= game_loop_exe 
#HAY QUE PONER MAS
#########################################################
OBJECTS = command.o game_loop.o game.o graphic_engine.o screen.o space.o 
OBJECTSCOMMAND = command.o
OBJECTSGALOOP = game_loop.o
OBJECTSGAME = game.o
OBJECTSGRAPHIC = graphic_engine.o
OBJECTSSCREEN = screen.o
OBJECTSSPACE = space.o

##HAY QUE PONER MAS
##########################################################
DIST_NAME = GAME_PROJECT_MORPHEUS
#HAY QUE PONER MAS
##########################################################
OBJECTS_TO_CLEAN = command.o game_loop.o game.o graphic_engine.o screen.o space.o
#HAY QUE PONER MAS
HEADERS_TO_SUBMIT =*.h
SOURCES_TO_SUBMIT = command.c game.c graphic_engine.c screen.c space.c game_loop.c
SUPPORT_TO_SUBMIT = makefile
#######################################################
#En el caso de que haya instrucciones adicionales.
MEMORIES_TO_SUBMIT =*.pdf

.PHONY: all
all: $(MODULOS)
#COMANDOS
#MIRAR SI HAY QUE ELIMINARLO
juego_fin_exe:$(OBJECTS)
	$(CC) $(CFLAGS) -o game_loop_exe $(OBJECTS)
game_loop.o:game_loop.c graphic_engine.h
	$(CC) $(CFLAGS) -c game_loop.c
command.o:command.c command.h
	$(CC) $(CFLAGS) -c command.c
#MIRAR SI HAY QUE ELIMINARLO
game.o: game.c game.h command.h space.h
	$(CC) $(CFLAGS) -c game.c
#MIRAR SI HAY QUE ELIMINARLO
graphic_engine.o :graphic_engine.c graphic_engine.h screen.h game.h
	$(CC) $(CFLAGS) -c graphic_engine.c
#MIRAR SI HAY QUE ELIMINARLO
screen.o: screen.c screen.h
	$(CC) $(CFLAGS) -c screen.c
#MIRAR SI HAY QUE ELIMINARLO
space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -c space.c


#HAY DUDA GENERALIZADA CON LAS DEPENDENCIAS DE LOS ARCHIVOS .h

.PHONY: valgrind
valgrind:
	valgrind juego_fin_exe --args data.dat

.PHONY: clear
clear:
	rm -rf $(OBJECTS_TO_CLEAN) *.dSYM #borra todos los objetos excepto el octaedro.o

.PHONY: clean
clean: clear
	rm -rf $(DIST_NAME) $(DIST_NAME).tar $(EJS) #para borrar los tar generados en caso de que se quiera . (con lo que tengan dentro - ejecutables)
	#tareas que otorgan distribucion (es decir facilidad para enviarlo)
.PHONY: dist
dist:
	@echo "Preparando para enviar"
	rm -f $(DIST_NAME).tar #si existe los soobrescribe (borra antes)
	mkdir -p $(DIST_NAME) #crea un directorio donde van a estar los archivos
	cp $(HEADERS_TO_SUBMIT) $(SOURCES_TO_SUBMIT) $(SUPPORT_TO_SUBMIT) $(MEMORIES_TO_SUBMIT) $(DIST_NAME)/  #se ponen en el directorio recien creado los archivos incluyendo pdfs
	zip $(DIST_NAME).tar $(DIST_NAME)/* #Se genera el comprimido .tar con el directorio creado
	rm -rf $(DIST_NAME)
	@echo "Estado:listo para enviar"
