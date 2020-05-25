" 让配置变更立即生效
autocmd BufWritePost $MYVIMRC source $MYVIMRC

set nu
set wrap
set nofoldenable
set mouse=a
set scrolloff=7 " 光标的上方或下方保留显示的行数
set updatetime=100
set timeoutlen=200
set foldmethod=indent " syntax
" set history=20000
set nofoldenable
set laststatus=2 " 总显示最后一个窗口的状态行；设为1则窗口数多于一个的时候显示最后一个窗口的状态行；0不显示最后一个窗口的状态行
set showcmd " 命令行显示输入的命令
set helplang=cn
set cursorline " 突出显示当前行

let g:mapleader = "\<Space>"
let g:maplocalleader = ";"

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

" 搜索
" 设置默认进行大小写不敏感查找
set ignorecase
" 如果有一个大写字母，则切换到大小写敏感查找
set smartcase
" 当光标一段时间保持不动了，就禁用高亮
autocmd cursorhold * set nohlsearch
" 当输入查找命令时，再启用高亮
noremap n :set hlsearch<cr>n
noremap N :set hlsearch<cr>N
noremap / :set hlsearch<cr>/
noremap ? :set hlsearch<cr>?
noremap * *:set hlsearch<cr>

" 自动换行缩进
set autoindent " essentially tells vim to apply the indentation of the current line to the next (created by pressing enter in insert mode or with O or o in normal mode.
set smartindent " reacts to the syntax/style of the code you are editing (especially for C).
set tabstop=4
set softtabstop=4 " 在按退格键时，如果前面有4个空格，则会统一清除
set shiftwidth=4  " 设定 << 和 >> 命令移动时的宽度为 4
set smarttab

" 备份
set nobackup
set nowritebackup
set undofile
set undodir=~/.config/nvim/undo
set noswapfile

" 中文，字體
set fileencodings=utf-8,gb2312,gb18030,gbk,chinese,ucs-bom,cp936,latin1,euc-jp,euc-kr  "显示中文
set encoding=utf-8
set fileencodings=utf-8

" 打开文件时恢复光标位置
autocmd BufReadPost *
    \	if line("'\"") > 1 && line("'\"") <= line("$") |
    \		exe "normal! g`\"" |
    \	endif

" github 鏡像
let g:plug_url_format = 'https://hub.fastgit.org/%s.git'

call plug#begin( stdpath('data') . '/plugged' )
	Plug 'yianwillis/vimcdoc' " cn doc
	Plug 'airblade/vim-gitgutter' " git gutter
	Plug 'tpope/vim-fugitive', { 'on': ['G', 'Git', 'Gfetch', 'Gpush', 'Glog', 'Gclog', 'Gdiffsplit']} " git
	Plug 'neoclide/coc.nvim', {'branch': 'release'} " auto complete
	Plug 'liuchengxu/vim-which-key', { 'on': ['WhichKey', 'WhichKey!'] } " menu
	Plug 'morhetz/gruvbox' " colorscheme
	Plug 'Yggdroot/LeaderF', { 'do': './install.sh' } " 模糊搜索
	Plug 'mhinz/vim-startify' " 启动界面
	Plug 'norcalli/nvim-colorizer.lua' " 颜色高亮
	Plug 'Yggdroot/indentLine' " 缩进显示
	Plug 'luochen1990/rainbow' " 彩虹括号
	Plug 'rhysd/accelerated-jk' " 加速 jk
	Plug 'psliwka/vim-smoothie' " 平滑移动
	Plug 'simnalamburt/vim-mundo' " 历史记录
	" Plug 'plasticboy/vim-markdown' " markdown
	Plug 'iamcco/markdown-preview.nvim', { 'do': { -> mkdp#util#install() } } " markdown preview
    " Plug 'rbgrouleff/bclose.vim'
	" Plug 'francoiscabrol/ranger.vim' "ranger
	Plug 'Shougo/defx.nvim', { 'do': ':UpdateRemotePlugins' }
		Plug 'kristijanhusak/defx-icons'
		Plug 'kristijanhusak/defx-git'
	Plug 'voldikss/vim-floaterm' " 浮动终端
	Plug 'tyru/caw.vim' " 注释
	" Plug 'hardcoreplayers/spaceline.vim' " line status
	Plug 'vim-airline/vim-airline'
		Plug 'vim-airline/vim-airline-themes'
	" 函数导航
	Plug 'liuchengxu/vista.vim'
	" c/c++ lsp highlight
	Plug 'jackguo380/vim-lsp-cxx-highlight'
	" quick run
	Plug 'skywind3000/asyncrun.vim'
	" Debugger
	Plug 'puremourning/vimspector', {'do': './install_gadget.py --enable-c --enable-python'}
	Plug 'ryanoasis/vim-devicons' " icon
call plug#end()
let g:which_key_map = {}

" modules
let $VIM_PATH =
	\	get(g:, 'etc_vim_path',
	\	exists('*stdpath') ? stdpath('config') :
	\		! empty($MYVIMRC) ? fnamemodify(expand($MYVIMRC), ':h') :
	\		! empty($VIMCONFIG) ? expand($VIMCONFIG) :
	\		! empty($VIM_PATH) ? expand($VIM_PATH) :
	\		fnamemodify(resolve(expand('<sfile>:p')), ':h:h')
	\	)
source $VIM_PATH/modules/defx.vim
source $VIM_PATH/modules/coc.vim

" debuger
" let g:vimspector_enable_mappings = 'HUMAN'
nmap <F3> <Plug>VimspectorStop
nmap <F4> <Plug>VimspectorRestart
nmap <F5> <Plug>VimspectorContinue
nmap <F6> <Plug>VimspectorPause
nmap <F9> <Plug>VimspectorToggleBreakpoint
nmap <F10> <Plug>VimspectorStepOver
nmap <F11> <Plug>VimspectorStepInto
" 🔴🔵🔶
sign define vimspectorBP text=☛ texthl=Normal
sign define vimspectorBPDisabled text=☞ texthl=Normal
sign define vimspectorPC text=🔶 texthl=SpellBad
" function! s:read_template_into_buffer(template)
" 	" has to be a function to avoid the extra space fzf#run insers otherwise
" 	execute '0r ~/.config/nvim/sample_vimspector_json/'.a:template
" endfunction
" command! -bang -nargs=* LoadVimSpectorJsonTemplate call fzf#run({
"	\	'source': 'ls -1 ~/.config/nvim/sample_vimspector_json',
"	\	'down': 20,
"	\	'sink': function('<sid>read_template_into_buffer')
"	\	})
" noremap <leader>vs :tabe .vimspector.json<CR>:LoadVimSpectorJsonTemplate<CR>

" quick run
" function! CompileRun() abort
" 	:AsyncRun -save=1 g++ -Wall -std=c++11 -O2 -Wno-unused-result "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"
" endfunction
" nnoremap <F12> :call CompileRun()<CR>
nnoremap <F1> :AsyncRun -save=1 g++ -Wall -std=c++11 -O2 -Wno-unused-result -g "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"<CR>
nnoremap <leader>lc :AsyncRun -save=1 g++ -Wall -std=c++11 -O2 -Wno-unused-result -g "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"<CR>
nnoremap <F12> :AsyncRun -mode=term -pos=right -raw -cwd=$(VIM_FILEDIR) "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"<CR>
nnoremap <leader>lr :AsyncRun -mode=term -pos=right -raw -cwd=$(VIM_FILEDIR) "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"<CR>
" autocmd User AsyncRunStop :call <SID>asyncrun_stop()
" function! s:asyncrun_stop()
" 	if (g:asyncrun_code ==# 0)
" 		:AsyncRun -mode=term -pos=right -raw -cwd=$(VIM_FILEDIR) "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"
" 		" cclose
" 		copen 4
" 	else
" 		copen 8
" 	endif
" endfunction
" Quickfix window
let g:asyncrun_open = 6
nnoremap <F12> :call asyncrun#quickfix_toggle(6)<cr>
" 命令结束后是否响铃
let g:asyncrun_bell = 1

" colorscheme
set bg=dark
set termguicolors
colorscheme gruvbox
" 透明
hi Normal	guibg=None ctermbg=None
hi NonText	guibg=None ctermbg=None
hi LineNr	guibg=None ctermbg=None
hi SignColumn guibg=None ctermbg=None
" Reload icons after init source
if exists('g:loaded_webdevicons')
	call webdevicons#refresh()
endif
let g:webdevicons_enable=1
" startify
let g:webdevicons_enable_startify=1
" line status
" let g:spaceline_seperate_style= 'arrow'
" let g:airline#extensions#tabline#formatter = ''
" let g:airline_theme=''
" let g:airline_powerline_fonts=1
let g:webdevicons_enable_airline_statusline=1
let g:webdevicons_enable_airline_tabline=1
" unicode symbols
" let g:airline_symbols = {}
" let g:airline_left_sep = '▶'
" let g:airline_right_sep = '◀'
" let g:airline_symbols.crypt = '🔒'
" let g:airline_symbols.linenr = '¶'
" let g:airline_symbols.branch = '⎇'
" let g:airline_symbols.paste = '∥'
" let g:airline_symbols.notexists = '∄'
" let g:airline_symbols.whitespace = 'Ξ'
let g:airline_theme='deus'
" deus solarized minimalist

" coc
" Give more space for displaying messages.
set cmdheight=1
" if hidden is not set, TextEdit might fail.
set hidden
" don't give |ins-completion-menu| messages.
set shortmess+=c
" always show signcolumns
set signcolumn=yes
" coc 擴展
let g:coc_global_extensions = [ 'coc-calc', 'coc-clangd', 'coc-cmake',
	\ 'coc-html', 'coc-highlight', 'coc-html', 'coc-css', 'coc-tabnine', 'coc-git',
	\ 'coc-json', 'coc-yaml', 'coc-explorer', 'coc-floaterm', 'coc-pairs',
	\ 'coc-vimlsp']

" coc-floaterm
nnoremap <LocalLeader>t :FloatermToggle<CR>
nnoremap <LocalLeader>n :FloatermNew
nnoremap <LocalLeader>j :FloatermNext<CR>
nnoremap <LocalLeader>k :FloatermPrev<CR>

" Startify

" Leaderf
" popup mode
let g:Lf_WindowPosition = 'popup'
let g:Lf_PreviewInPopup = 1
" let g:Lf_PreviewResult = {'Function': 1, 'BufTag': 1, 'File': 1 }
" show icons
let g:Lf_ShowDevIcons = 1
set ambiwidth=double
" shortcut
let g:Lf_ShortcutF = "<leader>ff"
let g:Lf_ShortcutB = "<Leader>fb"
let g:Lf_CommandMap = {'<A-K>': ['<Up>'], '<A-J>': ['<Down>']}
" noremap <leader>fb :<C-U><C-R>=printf("Leaderf buffer %s", "")<CR><CR>
noremap <leader>fm :<C-U><C-R>=printf("Leaderf mru %s", "")<CR><CR>
noremap <leader>ft :<C-U><C-R>=printf("Leaderf bufTag %s", "")<CR><CR>
noremap <leader>fl :<C-U><C-R>=printf("Leaderf line %s", "")<CR><CR>
" noremap <C-B> :<C-U><C-R>=printf("Leaderf! rg --current-buffer -e %s ", expand("<cword>"))<CR>
" noremap <C-F> :<C-U><C-R>=printf("Leaderf! rg -e %s ", expand("<cword>"))<CR>
" search visually selected text literally
xnoremap gf :<C-U><C-R>=printf("Leaderf! rg -F -e %s ", leaderf#Rg#visual())<CR>
noremap go :<C-U>Leaderf! rg --recall<CR>
" Leaderf gtags --update
let g:Lf_GtagsAutoGenerate = 1
let g:Lf_Gtagslabel = 'native-pygments'
noremap <leader>fr :<C-U><C-R>=printf("Leaderf! gtags -r %s --auto-jump", expand("<cword>"))<CR><CR>
noremap <leader>fd :<C-U><C-R>=printf("Leaderf! gtags -d %s --auto-jump", expand("<cword>"))<CR><CR>
noremap <leader>fo :<C-U><C-R>=printf("Leaderf! gtags --recall %s", "")<CR><CR>
noremap <leader>fn :<C-U><C-R>=printf("Leaderf gtags --next %s", "")<CR><CR>
noremap <leader>fp :<C-U><C-R>=printf("Leaderf gtags --previous %s", "")<CR><CR>

" git
let g:gitgutter_map_keys = 0
nmap <leader>g] <Plug>(GitGutterNextHunk)
nmap <leader>g[ <Plug>(GitGutterPrevHunk)
" 折叠
nmap <leader>gf :GitGutterFold<CR>zr
nmap <leader>gc :G commit<CR>

" spaceline.vim
" let g:spaceline_seperate_style= 'slant'

" indentLine
" each indent level has a distinct character
let g:indentLine_char_list = ['|', '¦', '┆', '┊']

" rainbow
let g:rainbow_active = 1
let g:rainbow_conf = {
	\	'guifgs': ['lightblue', 'lightyellow', 'darkorange3', 'seagreen3', 'firebrick', 'royalblue3'],
	\	'ctermfgs': ['lightblue', 'lightyellow', 'lightcyan', 'lightmagenta'],
	\	'operators': '_,_',
	\	'parentheses': ['start=/(/ end=/)/ fold', 'start=/\[/ end=/\]/ fold', 'start=/{/ end=/}/ fold'],
	\	'separately': {
	\		'*': {},
	\		'tex': {
	\			'parentheses': ['start=/(/ end=/)/', 'start=/\[/ end=/\]/'],
	\		},
	\		'lisp': {
	\			'guifgs': ['royalblue3', 'darkorange3', 'seagreen3', 'firebrick', 'darkorchid3'],
	\		},
	\		'vim': {
	\			'parentheses': ['start=/(/ end=/)/', 'start=/\[/ end=/\]/', 'start=/{/ end=/}/ fold', 'start=/(/ end=/)/ containedin=vimFuncBody', 'start=/\[/ end=/\]/ containedin=vimFuncBody', 'start=/{/ end=/}/ fold containedin=vimFuncBody'],
	\		},
	\		'html': {
	\			'parentheses': ['start=/\v\<((area|base|br|col|embed|hr|img|input|keygen|link|menuitem|meta|param|source|track|wbr)[ >])@!\z([-_:a-zA-Z0-9]+)(\s+[-_:a-zA-Z0-9]+(\=("[^"]*"|'."'".'[^'."'".']*'."'".'|[^ '."'".'"><=`]*))?)*\>/ end=#</\z1># fold'],
	\		},
	\		'css': 0,
	\	}
	\}

" accelerated-jk
nmap j <Plug>(accelerated_jk_gj)
nmap k <Plug>(accelerated_jk_gk)

" Graph your Vim undo tree in style.
nnoremap <leader>fh :MundoToggle<CR>

" markdown-preview
nmap <leader>lp <Plug>MarkdownPreviewToggle
let g:markdown_fenced_languages = ['css', 'js=javascript']
" set to 1, echo preview page url in command line when open preview page
" default is 0
let g:mkdp_echo_preview_url = 1
" sync_scroll_type: 'middle', 'top' or 'relative', default value is 'middle'
"   middle: mean the cursor position alway show at the middle of the preview page
"   top: mean the vim top viewport alway show at the top of the preview page
"   relative: mean the cursor position alway show at the relative positon of the preview page
let g:mkdp_preview_options = {
    \	'sync_scroll_type': 'middle',
	\	}

" Vista
nnoremap <F2> <ESC>:Vista!!<CR>
inoremap <F2> <ESC>:Vista!!<CR>
" How each level is indented and what to prepend.
" This could make the display more compact or more spacious.
" e.g., more compact: ["▸ ", ""]
" Note: this option only works the LSP executives, doesn't work for `:Vista ctags`.
let g:vista_icon_indent = ["╰─▸ ", "├─▸ "]
" To enable fzf's preview window set g:vista_fzf_preview.
" The elements of g:vista_fzf_preview will be passed as arguments to fzf#vim#with_preview()
" For example:
let g:vista_fzf_preview = ['right:50%']
" Ensure you have installed some decent font to show these pretty symbols,
" then you can enable icon for the kind.
let g:vista#renderer#enable_icon = 1
" The default icons can't be suitable for all the filetypes, you can extend it as you wish.
let g:vista#renderer#icons = {
	\	"function": "\uf794",
	\	"variable": "\uf71b",
	\	}
      	
" caw comment
nmap <Leader>c <Plug>(caw:prefix)
xmap <Leader>c <Plug>(caw:prefix)
nmap <Leader>cl <Plug>(caw:hatpos:toggle)
xmap <Leader>cl <Plug>(caw:hatpos:toggle)

" vim-which_key
nnoremap <silent> <leader> :WhichKey '<Space>'<CR>
nnoremap <silent> <localleader> :WhichKey ';'<CR>
let g:which_key_map = {
    \ 'name': '+ST-vim',
    \ 't' : ['tabnew', '新建 Tab'],
	\ 'n' : ['tabn', 'Tab Next'],
    \ '1' : [':tabn 1', 'tab-1'],
    \ '2' : [':tabn 2', 'tab-2'],
    \ '3' : [':tabn 3', 'tab-3'],
    \ '4' : [':tabn 4', 'tab-4'],
    \ '5' : [':tabn 5', 'tab-5'],
    \ '6' : [':tabn 6', 'tab-6'],
    \ '7' : [':tabn 7', 'tab-7'],
    \ '8' : [':tabn 8', 'tab-8'],
    \ '9' : [':tabn 9', 'tab-9'],
    \ }
let g:which_key_map['q'] = {
	\ 'name' : '+关闭',
    \ 'c' : ['tabclose', 'close-current-tab'],
	\ 'q' : ['q', 'quit'],
	\ 'a' : ['qa', 'quit all'],
	\ }
let g:which_key_map['w'] = {
    \ 'name' : '+windows' ,
    \ 'w' : ['<C-W>w'     , 'other-window']          ,
    \ 'd' : ['<C-W>c'     , 'delete-window']         ,
    \ '-' : ['<C-W>s'     , 'split-window-below']    ,
    \ '|' : ['<C-W>v'     , 'split-window-right']    ,
    \ '2' : ['<C-W>v'     , 'layout-double-columns'] ,
    \ 'h' : ['<C-W>h'     , 'window-left']           ,
    \ 'j' : ['<C-W>j'     , 'window-below']          ,
    \ 'l' : ['<C-W>l'     , 'window-right']          ,
    \ 'k' : ['<C-W>k'     , 'window-up']             ,
    \ 'H' : ['<C-W>5<'    , 'expand-window-left']    ,
    \ 'J' : ['resize +5'  , 'expand-window-below']   ,
    \ 'L' : ['<C-W>5>'    , 'expand-window-right']   ,
    \ 'K' : ['resize -5'  , 'expand-window-up']      ,
    \ '=' : ['<C-W>='     , 'balance-window']        ,
    \ 's' : ['<C-W>s'     , 'split-window-below']    ,
    \ 'v' : ['<C-W>v'     , 'split-window-below']    ,
    \ '?' : ['Windows'    , 'fzf-window']            ,
    \ }
let g:which_key_map.b = {
    \ 'name' : '+buffer' ,
    \ '1' : ['b1'        , 'buffer 1']        ,
    \ '2' : ['b2'        , 'buffer 2']        ,
    \ 'd' : ['bd'        , 'delete-buffer']   ,
    \ 'f' : ['bfirst'    , 'first-buffer']    ,
    \ 'h' : ['Startify'  , 'home-buffer']     ,
    \ 'l' : ['blast'     , 'last-buffer']     ,
    \ 'n' : ['bnext'     , 'next-buffer']     ,
    \ 'p' : ['bprevious' , 'previous-buffer'] ,
    \ '?' : ['Buffers'   , 'fzf-buffer']      ,
    \ }
let g:which_key_map.f = { 'name': '+find'}
let g:which_key_map.c = { 'name': '+comment'}
let g:which_key_map.g = { 'name': '+git'}
autocmd! User vim-which-key call which_key#register('<Space>', "g:which_key_map")

