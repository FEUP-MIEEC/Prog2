wget 'ftp://ftp.figlet.org/pub/figlet/program/unix/figlet-2.2.5.tar.gz'

tar -xvf figlet-2.2.5.tar.gz &> /dev/null
cd figlet-2.2.5
make &> /dev/null
cd ..

for i in {0..3}
do
   figlet-2.2.5/figlet -d figlet-2.2.5/fonts " => Aula "$i; cd Aula$i*; chmod +x build.sh; ./build.sh; cd ..
done

rm -r figlet-2.2.5

setup_git() {
	git config --global user.name "Dannyps"
	git config --global user.email "danny@dannyps.net"
}

commit_website_files() {
	git add .
	git checkout -b build
	git commit --message "Travis build: $TRAVIS_BUILD_NUMBER"
}

upload_files() {
	git remote add origin-pages https://dannyps:${GH_TOKEN}@github.com/FEUP-MIEEC/Prog2.git #> /dev/null 2>&1
	git push --quiet --set-upstream origin-pages build
}

setup_git
commit_website_files
upload_files