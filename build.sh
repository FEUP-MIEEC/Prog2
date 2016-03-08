wget 'ftp://ftp.figlet.org/pub/figlet/program/unix/figlet-2.2.5.tar.gz'

tar -xvf figlet-2.2.5.tar.gz
cd figlet-2.2.5
make 
cd ..

for i in {0..3}
do
   figlet-2.2.5/figlet -d figlet-2.2.5/fonts " => Aula "$i; cd Aula$i*; chmod +x build.sh; ./build.sh; cd ..
done


git config --global user.name "Daniel Silva"
git config --global user.email "danny@dannyps.net"
git init
git remote add origin https://spongy:${GH_TOKEN}@github.com/FEUP-MIEEC/Prog2 #>/dev/null
git checkout --orphan gh-pages
git add .
git commit -q -m "Deploy $(date)" #&> /dev/null
git push -q -f origin gh-pages #&> /dev/null