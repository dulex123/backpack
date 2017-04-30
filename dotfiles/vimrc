call plug#begin('~/.vim/plugged')

Plug 'scrooloose/nerdtree'
Plug 'tpope/vim-eunuch'
Plug 'tyrannicaltoucan/vim-quantum'
Plug 'tpope/vim-fugitive'
Plug 'scrooloose/syntastic'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'junegunn/goyo.vim'
Plug 'junegunn/limelight.vim'
Plug 'scrooloose/nerdcommenter'
Plug 'itmammoth/doorboy.vim'
call plug#end()


let mapleader=","

filetype plugin on
let g:limelight_conceal_ctermfg = 'gray'

" ===== AIRLINE ====== "
    let g:airline_powerline_fonts = 1

    set noshowmode
    let g:airline_theme='luna'
    set laststatus=2

    " Enable the list of buffers
    let g:airline#extensions#tabline#enabled = 1
    let g:airline#extensions#tabline#show_buffers = 1


    " enable/disable fugitive/lawrencium integration
    let g:airline#extensions#branch#enabled = 1

    " Show just the filename
    let g:airline#extensions#tabline#fnamemod = ':t'

    set hidden
" ===== AIRLINE ====== "


let NERDTreeShowHidden=1
let NERDTreeMinimalUI = 1
let NERDTreeDirArrows = 1

set tabstop=8 softtabstop=0 expandtab shiftwidth=4 smarttab
set number


"Shortcuts"
    nmap <S-j> :bprevious<CR>
    nmap <S-k> :bnext <CR>
    nmap <leader>t :enew <cr>
    nmap <leader>w :bp <BAR> bd #<CR>
    nmap <leader>q :xa <CR>
    nmap <leader>s :w <CR>
    
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

"Themes"
    set termguicolors
    let g:quantum_black=1
    let g:quantum_italics=1
    colorscheme quantum
    "let g:airline_theme='quantum'
