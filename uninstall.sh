#!/bin/bash
rm -rf $HOME/.MakeClass
sed -i '/alias MakeClass="~\/.MakeClass\/run.sh"/d' ~/.zshrc
echo "Uninstallation complete."