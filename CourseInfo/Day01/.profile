# .profile for phaskell
#

# Some useful Bash configurations.
export ignoreeof=1 # Do not log out with ctrl-D
export noclobber=1 # File output redir cannot overwrite existing file

# Settings for command history.
shopt -s histappend
HISTSIZE=1000
HISTFILESIZE=1000

# Check terminal window size after every command.
shopt -s checkwinsize

# Basic info on current computer server.
export ARCH=`uname -m`
export HOST=`uname -n`

#
# Set a nice command prompt,
# with directory path and command number.
PS1='\n\w> \!: '


# Set aliases
alias cp="\cp -i"  # ask before overwrite
alias echo="\echo -e"  # handle escape sequences
alias hi="history"
alias j="jobs"
alias ls="\ls -CF --color=auto"
alias ll="\ls -acFo --color=auto"
alias mv="\mv -i"  # ask before overwrite

##
## Everyone look here!
##

## If Windows keep these lines
export PATH=$PATH:/c/MinGW/mingw64/bin:/c/MinGW/bin:.
alias make=mingw32-make

## If Mac or Linux (or WSL) keep these lines
export PATH=$PATH:.
