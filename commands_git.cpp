COMANDOS DE GIT - RESUMEN

===============
CONFIGURACION
===============
//configurar el nombre & email del usuario
git config --global user.name "mi nombre"
git config --global user.email "mi email"

//listar las configuraciones
git config --list

===============
GENERAL
===============
//Ver el historial de commits
git log
git log --stat //ver con estadisticas

//ver los cambios que se hicieron en un commit anterior
git show 3e2h329h293eh29 //hash del commit
git show a.cpp //cambios que se hicieron en a.cpp


===============
STAGGING AREA
===============
//verificar el estatus de git( archivos nuevos, editados, borrados, etc)
git status

//Agregar los archivos editados a el stagging Area
git add a.txt b.txt c.txt
git add .

//mandar los cambios a la rama Actual
git commit -m "Haciendo el commit"
  
//quitar todos los cambios puestos en el stagging Area
git reset HEAD //quita los cambios sin eliminar nada en hard disk
git rm --cached a.txt //quita los cambios de a.txt sin eliminar nada en hard disk
git rm --force a.txt  //quita los cambios de a.txt eliminado el archivo de hard disk

  
==================
EN ALGUNA RAMA "X"
==================
//regresar todo a un commit anterior
git reset 34h7fhd3da --soft //mantiene aun la capacidad de deshacer 
git reset 34h7fhd3da --hard //Ya no se puede deshacer

//posicionarse en algun commit o version o rama, sin perder los cambios q se hayan hecho.
git checkout master //regresa a la rama master
git checkout 23d3fhhdh3 //puedes tomar este commit como una rama, se puede crear una rama estando aqui
git checkout 3hj8frh4f4 a.cpp //nos da la version del archivo a.cpp en el commit 3hj8frh4f4

//ver las diferencias entre 2 commits
git diff 3ed2rf23 8sdff2f2

//operaciones con Ramas
git branch 0NuevaRama //creando nueva rama partiendo desde rama "X"
git branch 0NuevaRama 23dr3r4rr // creando nueva rama partiendo desde un commit especifico
git merge 0RamaY //haciendo merge de la RamaY( traer y fusionar los cambios de ramaY a la rama "X" o rama actual )
                 //me abre un vim , ya que es como un commit, se necesita un mensaje para el merge
                 //en caso de conflicto, aceptar los cambios que llegan a la rama "X" o rechazarlos

