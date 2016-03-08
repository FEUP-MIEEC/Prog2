wget 'ftp://ftp.figlet.org/pub/figlet/program/unix/figlet-2.2.5.tar.gz'

tar -xvf figlet-2.2.5.tar.gz
cd figlet-2.2.5
make 
cd ..

for i in {0..3}
do
   figlet-2.2.5/figlet -d figlet-2.2.5/fonts " => Aula "$i; cd Aula$i*; chmod +x build.sh; ./build.sh; cd ..
done


