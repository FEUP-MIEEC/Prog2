 exit 0
 
 # Prog2  [![Build Status](https://travis-ci.org/FEUP-MIEEC/Prog2.svg?branch=master)](https://travis-ci.org/FEUP-MIEEC/Prog2)
#Exercícios propostos/projetos nas aulas de Programação 2. 

#Há uma cópia do repositório *master* [aqui](https://github.com/FEUP-MIEEC/Prog2/tree/build) (*build*), com o resultado da compilação de todos os exercícios, bem com os seus executáveis. Alguns contêm, ainda, o output produzido.


git config --global user.name "Dannyps"
git config --global user.email "danny@dannyps.net"
git init
git remote add origin "https://dannyps:${GH_TOKEN}@github.com/FEUP-MIEEC/Prog2"
#git checkout -b build
git commit --message "Travis build: $TRAVIS_BUILD_NUMBER"
git add .
# Force push from the current repo's master branch to the remote
# repo's gh-pages branch. (All previous history on the gh-pages branch
# will be lost, since we are overwriting it.) We redirect any output to
# /dev/null to hide any sensitive credential data that might otherwise be exposed.
git push --force --quiet origin build


