COMANDOS DE GIT - RESUMEN - POR FRANKS JHON

//lista inmortal de alumnos de platzi que siguieron el curso
//de git y github by Platzi
https://freddier.github.io/hyperblog/blogpost.html

===============
CONFIGURACION
===============
//configurar el nombre & email del usuario
git config --global user.name "mi nombre"
git config --global user.email "mi email"
git config --global init.defaultBranch main
git config --global color.ui auto


//listar las configuraciones
git config --list

===============
GENERAL
===============

//acceder a la documentacion de cualquier comando git
git <command> --help

//Ver el historial de commits
git log
git log --stat //ver con estadisticas
git log --stat --all --graph --decorate --oneline // mas comprimido y en arbolito

//Podemos hacer un alias para estos comandos largos
//alias con 'linux'( queda guardado en ram?? )
alias arbolito="git log --stat --all --graph --decorate --oneline"
//en la 'configuracion de git'( queda guardado en hard disk )
git config --global alias.arbolito "log --graph --abbrev-commit --decorate --date=relative --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)- %an%C(reset)%C(bold yellow)%d%C(reset)' --all"

//ver los cambios que se hicieron en un commit anterior
git show 3e2h329h293eh29 //hash del commit
git show a.cpp //cambios que se hicieron en a.cpp

//borrar archivos trackeados por git( no incluyen los archivos reconocidos por .gitignore )
//que no necesitamos, ojo estos archivos son nuevos( no pasaron por 'git add .' )
git clean --dry-run //nos advierte cuales se borraran
git clean -f        //removera todos los archivos advertidos
git clean -df       //el parametro de borrara tambien los archivos untracked(no trackeados debido a .gitignore)

=============================================================================
    BUSCANDO KEYWORDS - STATS - COUNT WORDS - OCCURENCES - COMMITS AUTHORS
=============================================================================
//buscar palabras en ficheros
git grep color //muestra los ficheros donde hay ocurrencias.
git grep -n color // -n : muestra tambien la linea donde hubo ocurrencia
git grep -c color // -c : cuenta el numero de ocurrencias de color por fichero

//buscar palabras en commits
git log -S "color" 

//comandos y recursos colaborativos
git shortlog     //commits y su respectivo autor
git shortlog -sn //contador de commits de cada autor
git shortlog -sn --all // |--> se suman los que han sido eliminados tambien

git blame miarchivo.txt //muestra linea por linea quien modifico tal linea.
git blame miarchivo.txt -L2:5 //desde la linea 2 hasta la linea 5

===============
STAGGING AREA - no tracked files
===============
//verificar el estatus de git( archivos nuevos, editados, borrados, etc)
git status

//Agregar los archivos editados a el stagging Area
git add a.txt b.txt c.txt
git add .

//mandar los cambios a la rama Actual
git commit -m "Haciendo el commit"
git commit -am "Haciendo (add .) y luego (commit)"

//reconstruir un commit
//me equivoque y no olvide hacer un cambio que deberia ir en el ultimo commit??
git add archivomodificado //muy importante hacer git add, para tenerlo en el stagging area listo para commit
git commit --amend         //se abrira un vim, podriamos cambiar tambien el nombre del commit
                          //y asi los cambios se agregaran a mi ultimo commit
git commit --amend --no-edit // no se abrira vim, permanece el mensaje del commit                          

//quitar todos los cambios puestos en el stagging Area
git reset HEAD //quita los cambios sin eliminar nada en hard disk
git rm --cached a.txt //quita los cambios de a.txt sin eliminar nada en hard disk
git rm --force a.txt  //quita los cambios de a.txt eliminado el archivo de hard disk

//STACHED - nos sive para guardar cambios que no han sido agregados
//a el stagging area, son simplemente cambios que podemos guardar en memoria
//y regresar a el ultimo commit actualizado de nuestra rama actual

//guardar los ultimos cambios en un stash
git stash
git stash save "mensaje: Guardando cambios que aun no necesito"
//stash = todos los cambios que hice, pero por alguna razon no los quiero por ahora

//lista de todos mis stash
git stash list

//recuperar la memoria de los cambios en mi stash a mi rama actual
git stash pop

//eliminar la memoria de mi stash
git stash drop

//guardar los cambios en memoria en una rama nueva
git stash //primero guardar los cambios en memoria
git stash branch ramaNuevaDeStash
  
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

//Traer un commit de alguna rama al head de mi rama actual( MALA PRACTICA )
git cherry-pick 23h23hd29h    //hace un commit copia del commit que se trae( 23h23hd29h ) 
git cherry-pick 23h23hd29h -e //permite editar el mensaje del commit
git cherry-pick 23h23hd29h -n //trae los cambios del commit, pero no hace commit

=======================
    BRANCHES - RAMAS
=======================
//visualizar las ramas 
git branch       //ramas locales actuales
git branch --all //mas detalles ramas remotas ejemplo
git branch -a    //lo mismo que --all
git branch -r    //ramas remotas 

//visualizar commits en ramas
git show-branch
git show-branch --all // mas detalles

//CREANDO RAMAS
    //posicionarme en alguna rama master por ejemplo
    git checkout master
    //creando la rama
    git branch ramaFranks
    git branch ramaJhon
    //ahora enviar la rama a el repositorio remoto
    git push origin ramaFranks
    git push origin ramaJhon    

//eliminar Ramas
git branch -d ramaFranks //git branch --delete ramaFranks
git branch -D ramaFranks //git branch --delete --force ramaFranks
//-d "cuando todo se haya hecho push y merge"
//-D "no importa el status, se elimina la rama, cuidado con este commando"

//eliminar Ramas en remoto
git push <remote-name> --delete <branch-name>
git push origin --delete ramaABorrar

//Rebase!! - este comando no es de buena practica, pero util si queremos borrar rastro
//de que creamos una rama, posiblemente errada e innecesaria ( MALA PRACTICA )
//El util funcionamiento seria, por ejemplo:
//          1) Creo la rama Chiste, desde la rama master, y hago algunas modificaciones.
//              estas modificaciones las debi hacer en master, no habia ningun problema.
//          2) Ahora avance algunas modificaciones en master, y tengo q juntar todo, hacer un 
//             merge de master y Chiste, pero quedaran historia de que cree una rama innecesaria
//          3) Solucion: REBASE - de la siguiente manera.
                    git checkout Chiste
                    //hago quiza algunos cambios extras
                    git commit -am "cambios en Chiste"
                    git rebase master //me traigo los cambios de master
                    
                    git checkout master
                    git rebase Chiste //unifico entonces la historia de rama Chiste en la rama master
                                      //como si nunca hubiera existido la rama Chiste, como una lista
                                      //de commits de manera lineal, di quiero elimino la rama Chiste.
                                      //y no queda rastro alguno de que hize cosas feas , OJO no se borra
                                      //la historia de commits de ramaChiste, estos commits se copian como
                                      //si los hubiera hecho en master.


===============
    GITHUB
===============

//agregar el origin a mi repositorio local, desde el repositorio en github
git remote add origin url_repo.git

//agregar otra fuente remota
git remote add <nombre_del_remoto> <url_del_remoto>
git remote upstream url_nueva_repo.git

//verificar las conexiones a el repositorio remoto
git remote -v

//Eliminar la conexion a el repositorio remoto
git remote remove origin

//Enviar la rama elegida(ejemplo master) a el repositorio remoto
git push origin master
git push origin MiRama

//Descargar los cambios que se hayan hecho en el repositorio remoto
git pull origin master
//Descargar los cambios, permitir juntar los repositorios sin historias relacionadas
git pull origin master --allow-related-histories

=============================
CONEXION MEDIATE SSH A GITHUB
=============================
//Generar una nueva llave SSH: (Cualquier sistema operativo)
ssh-keygen -t rsa -b 4096 -C "youremail@example.com"
/*
    Se generan 2 archivos, id_rsa y id_rsa.pub, llave privada y llave publica respectivamente
    la clave privada la agregamos a el ssh agent y la protegenemos de la siguiente manera.
*/
//Comprobar proceso y agregarlo
eval $(ssh-agent - s)
ssh-add ~/.ssh/id_rsa

//Ahora en la pagina web de Github, ingresar a
//Mi Perfil -> Setting -> [New SSH Key] ->
// y agregamos un titulo a la SSH Key y copiar muy importante
//nuestra clave publica( id_rsa.pub ) y Aceptar.

//Para terminar debemos actualizar la url de conexion de nuestro repositorio Remoto
git remote -v //verificamos que teniamos ya un remote a nuestro repositorio remoto
git remote set-url origin git@github.com:gitczfranks/About-Git.git //
git remote -v //verificamos que la url ha cambiado

//Actualizar con 'pull'  y hacer cambios 'commit' en nuestro repositorio local
//al momento de hacer un 'push' a el repo remoto, aceptar 'yes' conectar y agregar
// permanentemente nuestra conexion RSA a nuestra lista conocida de hosts.


============
    TAGS
============
//con estos podemos tener etiquetas de versiones o commits, de un proyecto
//es muy util

//Agregando tags
git tag -a NombreDeMiTag -m "Mensaje de la creacion del tag"

//ver lista de tags
git tag             //solo nombres
git show-ref --tags //con mas detalles

//enviar los tags a nuestro repositorio remoto
git status //no se visualiza nada, los tags no son cambios
git push origin --tags

//Eliminar los tags
git tag -d NombreDeMiTag //se elimina de nuestro repositorio local
git push origin --tags   //se actualizan los tags, pero si borre algun tag local
                         //no se borrara en el repositorio remoto
git push origin :refs/tags/NombreDeMiTag //se actualiza el tag, se borra en caso de que lo borre en local                         


============================
    CREANDO PULL REQUEST
============================
//Si una rama es modificada y esta necesita ser agregada
//a master , es de buena practica crear un pull request
//para que el encargado del repositorio pueda aceptar los cambios
//hechos y poder hacer un merge entre la rama y el master del repositorio

vease la imagen [images/pull-request.png]

=================
    FORK
=================
//si queremos aportar a un repositorio podemos hacer un fork o bifurcacion
//del proyecto y hacer las modificaciones y pedir un pull request
//a el duenio del repositorio

vease la imagen [images/forks.png]

//Para tener actualizado el nuestro repositorio {fork-eado}
//debemos tener una fuente remota adicional que apunte directamente
//al el repositorio original [ NO nuestro repo fork-eado]
git remote add upstream repo_original.git //tanto 'upstream' como 'origin' solo son nombres a los remotos

//actualizamos nuestro repo local fork-eado, asi ya tenemos el repositorio local actualizado
git pull upstream master

//ahora actualizamos nuestro repositorio remoto fork-eado
git push origin master

//Ya podemos hacer modificaciones y mandar pull request a el repositorio original
//si queremos seguir aportando

================
  GITHUB PAGES
================

//Crear una pagina web mediante el dominio que nos brinda https://pages.github.com/
//es gratis.
