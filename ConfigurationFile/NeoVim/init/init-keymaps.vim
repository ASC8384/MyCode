" ============================
"
" keymaps.vim - 自定义按键
"
" Author: ASC_8384
" Create: 2021-04-05
"
" ============================

"----------------------------------------------------------------------
" 命令模式的快速移动
"----------------------------------------------------------------------
cnoremap <c-h> <left>
cnoremap <c-j> <down>
cnoremap <c-k> <up>
cnoremap <c-l> <right>
cnoremap <c-a> <home>
cnoremap <c-e> <end>
cnoremap <c-f> <c-d>
cnoremap <c-b> <left>
cnoremap <c-d> <del>
cnoremap <c-_> <c-k>

inoremap jk <ESC>
nnoremap <C-a> ggVG"+y
" nmap <c-j> <c-w>j
" nmap <c-k> <c-w>k
" nmap <c-h> <c-w>h
" nmap <c-l> <c-w>l
nnoremap <Leader>v :tabedit $MYVIMRC<cr>
" nmap <Leader>c :close<CR>
" nnoremap <Leader>q :q<cr>
inoremap <LocalLeader>w <ESC>:w<Cr>
xnoremap <LocalLeader>y "+y
nnoremap <Leader>p "+p
" 调整整体缩进后自动选中，方便再次操作
vnoremap < <gv
vnoremap > >gv
" 上下左右
inoremap <A-h> <left>
inoremap <A-j> <down>
inoremap <A-k> <up>
inoremap <A-l> <right>
" 单词转大写
inoremap <A-u> <ESC>gUiwea

