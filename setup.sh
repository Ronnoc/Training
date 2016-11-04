# vim 
mkdir -p ~/.vim/autoload
curl -fLo ~/.vim/autoload/plug.vim \
      https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
curl -fLo ~/.vimrc \
      https://raw.githubusercontent.com/Ronnoc/Training/master/.vimrc

# oh-my-zsh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
