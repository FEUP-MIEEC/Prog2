wget 'ftp://ftp.figlet.org/pub/figlet/program/unix/figlet-2.2.5.tar.gz'

tar -xvf figlet-2.2.5.tar.gz &> /dev/null
cd figlet-2.2.5
make &> /dev/null
cd ..

for i in 1 2 4 5
do
   figlet-2.2.5/figlet -d figlet-2.2.5/fonts " => Aula "$i; cd Aula$i*; chmod +x build.sh; ./build.sh; cd ..
done

figlet-2.2.5/figlet -d figlet-2.2.5/fonts " => Extras"; cd Extras; chmod +x build.sh; ./build.sh; cd ..

rm -r figlet-2.2.5

chmod +x git.sh
./git.sh