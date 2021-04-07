" ============================
"
" init.vim - initialize config
"
" Author: ASC_8384
" Create: 2021-04-03
" 
" ============================

" 防止重复加载
if get(s:, 'loaded', 0) != 0
	finish
else
	let s:loaded = 1
endif

" 让配置变更立即生效
" autocmd BufWritePost $MYVIMRC source $MYVIMRC

" Initialize base requirements
if has('vim_starting')
	" Global Mappings "{{{
	" Use spacebar as leader and ; as secondary-leader
	" Required before loading plugins!
	let g:mapleader="\<Space>"
	let g:maplocalleader=';'
	" Release keymappings prefixes, evict entirely for use of plug-ins.
	nnoremap <Space>  <Nop>
	xnoremap <Space>  <Nop>
	nnoremap ,        <Nop>
	xnoremap ,        <Nop>
	nnoremap ;        <Nop>
	xnoremap ;        <Nop>
endif


" 获取本文件所在目录
let $VIM_PATH =
	\	get(g:, 'etc_vim_path',
	\	exists('*stdpath') ? stdpath('config') :
	\		! empty($MYVIMRC) ? fnamemodify(expand($MYVIMRC), ':h') :
	\		! empty($VIMCONFIG) ? expand($VIMCONFIG) :
	\		! empty($VIM_PATH) ? expand($VIM_PATH) :
	\		fnamemodify(resolve(expand('<sfile>:p')), ':h:h')
	\	)
if has('nvim')
	let $VIM_DATA = stdpath('data')
endif

" 将目录加入 runtimepath 中
exec 'set rtp+='.$VIM_PATH

" 定义一个命令用来加载文件
command! -nargs=1 LoadScript exec 'so '.$VIM_PATH.'/'.'<args>'

" 加载基础设置
LoadScript init/init-config.vim
LoadScript init/init-keymaps.vim
LoadScript init/init-plugins.vim
LoadScript init/init-style.vim
" source $VIM_PATH/init

