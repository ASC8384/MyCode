" ============================
"
" init-basic.vim - 基础设置
"
" Author: ASC_8384
" Create: 2021-04-03
"
" ============================

" -----------------------------------------------------------------
" 基础设置
" -----------------------------------------------------------------
" 禁用 vi 兼容模式
set nocompatible
" 开启自动换行
set wrap
set mouse=a
" 光标的上方或下方保留显示的行数
set scrolloff=7
set updatetime=100
" set history=20000
" 总显示最后一个窗口的状态行；设为1则窗口数多于一个的时候显示最后一个窗口的状态行；0不显示最后一个窗口的状态行
set laststatus=2
" 设置 Backspace 键模式
set bs=eol,start,indent
" 设置中文帮助
set helplang=cn
" 突出显示当前行
set cursorline
" 显示光标位置
set ruler
" 打开功能键超时检测（终端下功能键为一串 ESC 开头的字符串）
set ttimeout
" 功能键超时检测 80 毫秒，键码上的超时
set ttimeoutlen=80
" 映射上的超时在 1 秒以后发生
set timeout
set timeoutlen=1000
" 行号设置
autocmd InsertEnter * :set norelativenumber
autocmd InsertLeave * :set relativenumber

" -----------------------------------------------------------------
" 搜索
" -----------------------------------------------------------------
" 设置默认进行大小写不敏感查找
set ignorecase
" 智能判断大小写，如果有一个大写字母，则切换到大小写敏感查找
set smartcase
" 当光标一段时间保持不动了，就禁用高亮
autocmd cursorhold * set nohlsearch
" 当输入查找命令时，再启用高亮
noremap n :set hlsearch<cr>n
noremap N :set hlsearch<cr>N
noremap / :set hlsearch<cr>/
noremap ? :set hlsearch<cr>?
noremap * *:set hlsearch<cr>
" 查找输入时动态增量显示查找结果
set incsearch

" -----------------------------------------------------------------
" 缩进设置
" -----------------------------------------------------------------
" 允许 Vim 自带脚本根据文件类型自动设置缩进等
if has('autocmd')
	filetype plugin indent on
endif
" 自动缩进
set autoindent " essentially tells vim to apply the indentation of the current line to the next (created by pressing enter in insert mode or with O or o in normal mode.
set smartindent " reacts to the syntax/style of the code you are editing (especially for C).
" 打开 C/C++ 语言缩进优化
set cindent
" 设置 TAB 高度
set tabstop=4
set softtabstop=4 " 在按退格键时，如果前面有4个空格，则会统一清除
set shiftwidth=4  " 设定 << 和 >> 命令移动时的宽度为 4
set smarttab
" expandtab
" 使用空格代替 TAB
set expandtab

augroup PythonTab
	au!
	" 如果你需要 python 里用 tab，那么反注释下面这行字，否则vim会在打开py文件
	" 时自动设置成空格缩进。
	au FileType python setlocal shiftwidth=4 tabstop=4 noexpandtab
augroup END

" -----------------------------------------------------------------
" 语法高亮设置
" -----------------------------------------------------------------
if has('syntax')
	syntax enable
	syntax on
endif

" -----------------------------------------------------------------
" 备份
" -----------------------------------------------------------------
set nobackup
set nowritebackup
" 创建 undo
set undofile
exec 'set undodir=' . $VIM_DATA . '/undo'
" 禁用交换文件
set noswapfile
" 允许备份
set backup
" 保存时备份
set writebackup
" 备份文件地址，统一管理
exec 'set backupdir=' . $VIM_DATA . '/backup'
" 备份文件扩展名
set backupext=.bak
" 创建目录，并且忽略可能出现的警告
" silent! call mkdir(expand(stdpath('data').'/backup'), "p", 0755)

" -----------------------------------------------------------------
" 编码设置，中文，字體
" -----------------------------------------------------------------
if has('multi_byte')
	" 内部工作编码
	set encoding=utf-8
	" 文件默认编码
	set fileencodings=utf-8
	" 打开文件时自动尝试下面顺序的编码
	set fileencodings=utf-8,gb2312,gb18030,gbk,chinese,ucs-bom,cp936,latin1,euc-jp,euc-kr
endif

" -----------------------------------------------------------------
" 代码折叠
" -----------------------------------------------------------------
if has('folding')
	set nofoldenable
	" 允许代码折叠
	" set foldenable
	" 代码折叠默认使用缩进
	" set fdm=indent
	" 默认打开所有缩进
	" set foldlevel=99
endif

" -----------------------------------------------------------------
" 文件搜索和补全时忽略下面的扩展名
" -----------------------------------------------------------------
set suffixes=.bak,~,.o,.h,.info,.swp,.obj,.pyc,.pyo,.egg-info,.class
set wildignore=*.o,*.obj,*~,*.exe,*.a,*.pdb,*.lib "stuff to ignore when tab completing
set wildignore+=*.so,*.dll,*.swp,*.egg,*.jar,*.class,*.pyc,*.pyo,*.bin,*.dex
set wildignore+=*.zip,*.7z,*.rar,*.gz,*.tar,*.gzip,*.bz2,*.tgz,*.xz    " MacOSX/Linux
set wildignore+=*DS_Store*,*.ipch
set wildignore+=*.gem
set wildignore+=*.png,*.jpg,*.gif,*.bmp,*.tga,*.pcx,*.ppm,*.img,*.iso
set wildignore+=*.so,*.swp,*.zip,*/.Trash/**,*.pdf,*.dmg,*/.rbenv/**
set wildignore+=*/.nx/**,*.app,*.git,.git
set wildignore+=*.wav,*.mp3,*.ogg,*.pcm
set wildignore+=*.mht,*.suo,*.sdf,*.jnlp
set wildignore+=*.chm,*.epub,*.pdf,*.mobi,*.ttf
set wildignore+=*.mp4,*.avi,*.flv,*.mov,*.mkv,*.swf,*.swc
set wildignore+=*.ppt,*.pptx,*.docx,*.xlt,*.xls,*.xlsx,*.odt,*.wps
set wildignore+=*.msi,*.crx,*.deb,*.vfd,*.apk,*.ipa,*.bin,*.msu
set wildignore+=*.gba,*.sfc,*.078,*.nds,*.smd,*.smc
set wildignore+=*.linux2,*.win32,*.darwin,*.freebsd,*.linux,*.android

" -----------------------------------------------------------------
" 其它设置
" -----------------------------------------------------------------
" 显示匹配的括号
set showmatch
" 显示括号匹配的时间
set matchtime=2
" 显示最后一行
set display=lastline
" 允许下方显示目录
set wildmenu
" 延迟绘制（提升性能）
set lazyredraw
" 错误格式
set errorformat+=[%f:%l]\ ->\ %m,[%f:%l]:%m
" 设置分隔符可视
" 注释，以使用 indentLine 插件
set listchars=tab:\|\ ,trail:.,extends:>,precedes:<
" 如遇Unicode值大于255的文本，不必等到空格再折行
set formatoptions+=m
" 合并两行中文时，不在中间加空格
set formatoptions+=B
" 文件换行符，默认使用 unix 换行符
set ffs=unix,dos,mac

" 打开文件时恢复光标位置
autocmd BufReadPost *
	\	if line("'\"") > 1 && line("'\"") <= line("$") |
	\		exe "normal! g`\"" |
	\	endif

" 定义一个 DiffOrig 命令用于查看文件改动
if !exists(":DiffOrig")
  command DiffOrig vert new | set bt=nofile | r ++edit # | 0d_ | diffthis
          \ | wincmd p | diffthis
endif
