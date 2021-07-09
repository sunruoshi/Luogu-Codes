" ---------------------------------------------------------------------
"    _____                  _                 _                       
"   / ___/ ____ _ ____ ___ ( )_____   _   __ (_)____ ___   _____ _____
"   \__ \ / __ `// __ `__ \|// ___/  | | / // // __ `__ \ / ___// ___/
"  ___/ // /_/ // / / / / / (__  )   | |/ // // / / / / // /   / /__  
" /____/ \__,_//_/ /_/ /_/ /____/    |___//_//_/ /_/ /_//_/    \___/  
"                                                                    
" ---------------------------------------------------------------------
"
" Sam's (not so) minimal vimrc.
"
set nocompatible

call plug#begin()

Plug 'sheerun/vim-polyglot'
Plug 'rakr/vim-one'
Plug 'joshdick/onedark.vim'
Plug 'itchyny/lightline.vim'
Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'ycm-core/YouCompleteMe'
Plug 'Yggdroot/indentLine'

call plug#end()

let g:ycm_extra_conf_globlist = ['~/Dev/*','!~/*']
let g:cpp_class_scope_highlight = 1
let g:cpp_member_variable_highlight = 1
let g:cpp_class_decl_highlight = 1
let g:cpp_no_function_highlight = 1
let g:lightline = {
      \ 'colorscheme': 'onedark',
      \ }


colorscheme onedark

set nobackup
set nowb
set noswapfile

filetype plugin indent on  " Load plugins according to detected filetype.
syntax on                  " Enable syntax highlighting.

set autoindent             " Indent according to previous line.
set expandtab              " Use spaces instead of tabs.
set softtabstop =4         " Tab key indents by 4 spaces.
set shiftwidth  =4         " >> indents by 4 spaces.
set shiftround             " >> indents to next multiple of 'shiftwidth'.

set backspace   =indent,eol,start  " Make backspace work as you would expect.
set hidden                 " Switch between buffers without having to save first.
set laststatus  =2         " Always show statusline.
set display     =lastline  " Show as much as possible of the last line.

set noshowmode             " Show current mode (or not) in command-line.
set showcmd                " Show already typed keys when more are expected.

set incsearch              " Highlight while searching with / or ?.
set hlsearch               " Keep matches highlighted.

set ttyfast                " Faster redrawing.
set lazyredraw             " Only redraw when necessary.

set splitbelow             " Open new windows below the current window.
set splitright             " Open new windows right of the current window.

set cursorline             " Find the current line quickly.
set wrapscan               " Searches wrap around end-of-file.
set report      =0         " Always report changed lines.
set synmaxcol   =200       " Only highlight the first 200 columns.

set list                   " Show non-printable characters.
set number                 " Show line numbers

if has('multi_byte') && &encoding ==# 'utf-8'
    let &listchars = 'tab:▸ ,extends:❯,precedes:❮,nbsp:±'
else
    let &listchars = 'tab:> ,extends:>,precedes:<,nbsp:.'
endif

" The fish shell is not very compatible to other shells and unexpectedly
" breaks things that use 'shell'.
if &shell =~# 'fish$'
    set shell=/bin/zsh
endif

if !has('gui_running')
  set t_Co=256
endif

" Auto complete quotes and brackets
inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap { {<CR>}<ESC>O
