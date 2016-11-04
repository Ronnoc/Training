# install vim 
mkdir -p ~/.vim/autoload
curl -fLo ~/.vim/autoload/plug.vim \
      https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

# oh-my-zsh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"

# my .vimrc 
curl -fLo ~/.vimrc https://raw.githubusercontent.com/Ronnoc/Training/master/.vimrc

# my .zshrc
curl -fLo ~/.zshrc https://raw.githubusercontent.com/Ronnoc/Training/master/.zshrc
