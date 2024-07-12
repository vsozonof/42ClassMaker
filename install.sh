mkdir $HOME/.MakeClass
cp MakeClass $HOME/.MakeClass
cp run.sh $HOME/.MakeClass
chmod +x $HOME/.MakeClass/run.sh
echo "alias MakeClass=\"~/.MakeClass/run.sh\"" >> ~/.zshrc