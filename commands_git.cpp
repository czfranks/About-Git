COMANDOS DE GIT - RESUMEN - POR FRANKS JHON

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
git log --stat --all --graph --decorate --oneline // mas comprimido y en arbolito

//Podemos hacer un alias para estos comandos largos
//alias con 'linux'( queda guardado en ram?? )
alias arbolito="git log --stat --all --graph --decorate --oneline"
//en la 'configuracion de git'( queda guardado en hard disk )
git config --global alias.superlog "log --graph --abbrev-commit --decorate --date=relative --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)- %an%C(reset)%C(bold yellow)%d%C(reset)' --all"

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
git commit -am "Haciendo (add .) y luego (commit)"
  
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

=======================
    BRANCHES - RAMAS
=======================
//visualizar las ramas 
git branch
git branch --all //mas detalles ramas remotas ejemplo

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
