set cin ls=2 ts=4 sts=4 sw=4 ttm=100
set hlsearch
syntax on
set shell=/bin/bash

set colorcolumn=80
highlight ColorColumn ctermbg=245

set cursorline
highlight CursorLine cterm=none ctermbg=232

nn <F7> :w <bar> :!vim %<_.in<left><left><left>

let g:powerline_pycmd="py3"
let g:leetcode_browser="firefox"

" Plug
call plug#begin('~/.vim/plugged')

Plug 'google/vim-maktaba'
Plug 'google/vim-codefmt'
Plug 'google/vim-glaive'

call plug#end()

" Formatting
nmap <C-K> <ESC>:FormatCode<CR>
vmap <C-K> <ESC>:'<,'>FormatLines<CR>

" C++
autocmd Filetype cpp nn <F8> :w <bar> :!clear && 
    \   cpplint %;
    \   echo '';
    \   g++ % -o %<.exe -std=c++17 -fsanitize=undefined -Wall -Wextra -Wshadow && 
    \   for i in %<_*.in; do 
    \       echo ==== $i ==== && 
    \       time ./%<.exe < $i && 
    \       echo ''; 
    \   done <CR>

autocmd Filetype cpp nn <F9> :w <bar> :!clear && 
    \   cpplint %;
    \   echo '';
    \   g++ % -o %<.exe -std=c++17 -fsanitize=undefined -Wall -Wextra -Wshadow &&
    \   echo '>>>' && 
    \   ./%<.exe <CR>

" Python
autocmd Filetype python nn <F8> :w <bar> :!clear &&
    \   for i in %<_*.in; do 
    \       echo ==== $i ==== && 
    \       python3 % < $i && 
    \       echo ''; 
    \   done <CR>

autocmd Filetype python nn <F9> :w <bar> :!clear &&
    \   echo '>>>' && 
    \   python3 %<CR>

