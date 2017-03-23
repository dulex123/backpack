call plug#begin('~/.vim/plugged')



"Markdown
Plug 'vim-airline/vim-airline'
Plug 'junegunn/goyo.vim'
Plug 'junegunn/limelight.vim'
Plug 'scrooloose/nerdcommenter'
Plug 'itmammoth/doorboy.vim'
call plug#end()
filetype plugin on
let g:limelight_conceal_ctermfg = 'gray'
let g:airline#extensions#tabline#enabled = 1
let mapleader=","

set tabstop=8 softtabstop=0 expandtab shiftwidth=4 smarttab
set number

"Indentation"
set smarttab
set shiftwidth=4
set softtabstop=4
set tabstop=4
set expandtab
set smartindent
set autoindent

"Swap files"
set noswapfile
set nobackup
set nowb
syntax on

