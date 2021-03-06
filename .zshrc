# ZSH的环境变量
export ZSH=$HOME/.oh-my-zsh
source $ZSH/oh-my-zsh.sh

# 256色Term 
export TERM=xterm-256color

# 主题设置
rvm_current() {
  rvm current 2>/dev/null
}

rbenv_version() {
  rbenv version 2>/dev/null | awk '{print $1}'
}

HOSTIP=`echo $SSH_CONNECTION |awk '{print $3}'`

local exit_code="%(?,,exit=%{$fg[red]%}%?%{$reset_color%})"

PROMPT='
%{$fg[white]%}[%w %*] \
%{$fg[blue]%}%n\
%{$fg[white]%}@\
%{$fg[green]%}%m#$HOSTIP\
%{$fg[white]%}:\
%{$fg[yellow]%}%~\
%{$fg[white]%} $exit_code
$%{$reset_color%} '

function my_git_prompt_info() {
  ref=$(git symbolic-ref HEAD 2> /dev/null) || return
  echo "$ZSH_THEME_GIT_PROMPT_PREFIX${ref#refs/heads/}$ZSH_THEME_GIT_PROMPT_SUFFIX"
}

RPROMPT='$(my_git_prompt_info)%{$reset_color%}'

# Must use Powerline font, for \uE0A0 to render.
ZSH_THEME_GIT_PROMPT_PREFIX="%{$fg[white]%}git:%{$fg[cyan]%}"
ZSH_THEME_GIT_PROMPT_SUFFIX="%{$reset_color%}"
ZSH_THEME_GIT_PROMPT_DIRTY="%{$fg[red]%}!"
ZSH_THEME_GIT_PROMPT_UNTRACKED="%{$fg[green]%}?"
ZSH_THEME_GIT_PROMPT_CLEAN=""

if [ -e ~/.rvm/bin/rvm-prompt ]; then
  RPROMPT='%{$fg_bold[red]%}‹$(rvm_current)›%{$reset_color%}'
else
  if which rbenv &> /dev/null; then
    RPROMPT='%{$fg_bold[red]%}$(rbenv_version)%{$reset_color%}'
  fi
fi


# 按tab键补全命令的时候,如果没什么可补全的就会出现三个红点
COMPLETION_WAITING_DOTS="true"

# 历史命令日期显示格式
HIST_STAMPS="yyyy-mm-dd"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# My Zsh Config
hash -d O='/mnt/ficuspi/ybkang/output/'
hash -d G='/mnt/ficuspi/ybkang/git/'
hash -d D='/mnt/ficuspi/ybkang/data/'
hash -d Q='/mnt/ficuspi/ybkang/'
hash -d P='/mnt/ficuspi/ybkang/project/'

alias -s cpp='vim'
alias -s json='vim'

alias go='gnome-open'
alias sc='scons -uj`nproc`'
alias gb='git branch'
alias gst='git status'
alias -g tmuxn='tmux new -s '$HOSTIP
alias -g tmuxa='tmux a -t '$HOSTIP

export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/local/cuda/lib64:/usr/local/cuda/extras/CUPTI/lib64"
export CUDA_HOME=/usr/local/cuda

eval $(dbus-launch --sh-syntax)

export DBUS_SESSION_BUS_ADDRESS
export DBUS_SESSION_BUS_PID

[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh
