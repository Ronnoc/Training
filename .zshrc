# ZSH的环境变量
export ZSH=$HOME/.oh-my-zsh

# 256色Term 
export TERM=xterm-256color

# 主题设置
rvm_current() {
  rvm current 2>/dev/null
}

rbenv_version() {
  rbenv version 2>/dev/null | awk '{print $1}'
}

local HOSTIP=`echo $SSH_CONNECTION |awk '{print $3}'`

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
RPROMPT='$(git_prompt_info)%{$reset_color%}'

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

# 插件设置，如果添加太多启动速度会比较慢
plugins=(git)

#plugins autojump
#[[ -s /mnt/ficuspi/ybkang/init/.autojump/etc/profile.d/autojump.sh ]] && source /mnt/ficuspi/ybkang/init/.autojump/etc/profile.d/autojump.sh
#autoload -U compinit && compinit -u

# My Zsh Config
hash -d O='/mnt/ficuspi/ybkang/output/'
hash -d G='/mnt/ficuspi/ybkang/git/'
hash -d D='/mnt/ficuspi/ybkang/data/'
hash -d Q='/mnt/ficuspi/ybkang/'
hash -d P='/mnt/ficuspi/ybkang/project/'

alias -s cpp='vim'
alias -s json='vim'

alias go='gnome-open'
alias sc='scons -uj`nproc` --verify-libdeps'

export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/local/cuda/lib64:/usr/local/cuda/extras/CUPTI/lib64"
export CUDA_HOME=/usr/local/cuda

eval $(dbus-launch --sh-syntax)

export DBUS_SESSION_BUS_ADDRESS
export DBUS_SESSION_BUS_PID

[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh

source $ZSH/oh-my-zsh.sh
