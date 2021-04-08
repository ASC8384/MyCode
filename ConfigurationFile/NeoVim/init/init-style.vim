" ============================
"
" init-style.vim - 显示设置
"
" Author: ASC_8384
" Create: 2021-04-05
"
" ============================

" -----------------------------------------------------------------
" 显示设置
" -----------------------------------------------------------------
" 总是显示状态栏
set laststatus=2
" 总是显示行号
set number
" 总是显示侧边栏（用于显示 mark/gitdiff/诊断信息）
set signcolumn=yes
" 总是显示标签栏
set showtabline=2
" 设置显示制表符等隐藏字符
set list
" 命令行显示输入的命令
set showcmd
" 水平切割窗口时，默认在右边显示新窗口
set splitright

" -----------------------------------------------------------------
" 主题设置
" -----------------------------------------------------------------
" colorscheme
set bg=dark
set termguicolors
colorscheme gruvbox
" 透明
hi Normal	guibg=None ctermbg=None
hi NonText	guibg=None ctermbg=None
hi LineNr	guibg=None ctermbg=None
hi SignColumn guibg=None ctermbg=None
" 允许 256 色
set t_Co=256


"------------------------------------------------------------------
" 状态栏设置
"------------------------------------------------------------------
" set statusline=                                 " 清空状态了
" set statusline+=\ %F                            " 文件名
" set statusline+=\ [%1*%M%*%n%R%H]               " buffer 编号和状态
" set statusline+=%=                              " 向右对齐
" set statusline+=\ %y                            " 文件类型
" 最右边显示文件编码和行号等信息，并且固定在一个 group 中，优先占位
" set statusline+=\ %0(%{&fileformat}\ [%{(&fenc==\"\"?&enc:&fenc).(&bomb?\",BOM\":\"\")}]\ %v:%l/%L%)

"------------------------------------------------------------------
" rainbow
"------------------------------------------------------------------
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

"------------------------------------------------------------------
" airline
"------------------------------------------------------------------
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
let g:airline_powerline_fonts=1
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

"------------------------------------------------------------------
" Other
"------------------------------------------------------------------
" spaceline.vim
" let g:spaceline_seperate_style= 'slant'
"
" indentLine
" each indent level has a distinct character
let g:indentLine_char_list = ['|', '¦', '┆', '┊']

