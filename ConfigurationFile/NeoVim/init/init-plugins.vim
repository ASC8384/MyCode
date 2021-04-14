" ============================
"
" init-plugins.vim - 插件设置
"
" Author: ASC_8384
" Create: 2021-04-05
"
" ============================

" github 鏡像
" let g:plug_url_format = 'https://hub.fastgit.org/%s.git'

"------------------------------------------------------------------
" 默认情况下的分组
"------------------------------------------------------------------
" if !exists('g:bundle_group')
" 	let g:bundle_group = ['basic', 'tags', 'enhanced', 'filetypes', 'textobj']
" 	let g:bundle_group += ['tags', 'airline', 'nerdtree', 'ale', 'echodoc']
" 	let g:bundle_group += ['leaderf']
" 	let g:bundle_group += ['keymaps']
" endif

"------------------------------------------------------------------
" 安装插件与配置
"------------------------------------------------------------------
call plug#begin( stdpath('data') . '/plugged' )

Plug 'yianwillis/vimcdoc' " cn doc
" Plug 'vimwiki/vimwiki' " Wikipedia

" -----------------------------------------------------------------
" basic
" -----------------------------------------------------------------
" if index(g:bundle_group, 'basic') >= 0
" 启动界面
Plug 'mhinz/vim-startify'
" 用于在侧边符号栏显示 marks （ma-mz 记录的位置）
Plug 'kshenoy/vim-signature'
Plug 'airblade/vim-gitgutter' " git gutter
Plug 'tpope/vim-fugitive', { 'on': ['G', 'Git', 'Gfetch', 'Gpush', 'Glog', 'Gclog', 'Gdiffsplit']} " git
Plug 'morhetz/gruvbox' " colorscheme
" endif

"------------------------------------------------------------------
" 增强插件
"------------------------------------------------------------------
" if index(g:bundle_group, 'enhanced') >= 0
Plug 'Yggdroot/LeaderF', { 'do': './install.sh' } " 模糊搜索
" 自动选择符号内文本
Plug 'gcmt/wildfire.vim'
" endif

"------------------------------------------------------------------
" 文件类型扩展
"------------------------------------------------------------------
" if index(g:bundle_group, 'filetypes') >= 0
" c/c++ lsp highlight
Plug 'jackguo380/vim-lsp-cxx-highlight'
" endif

"------------------------------------------------------------------
" airline
"------------------------------------------------------------------
" if index(g:bundle_group, 'airline') >= 0
" Plug 'hardcoreplayers/spaceline.vim' " line status
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
" endif

Plug 'neoclide/coc.nvim', {'branch': 'release'} " auto complete
Plug 'liuchengxu/vim-which-key', { 'on': ['WhichKey', 'WhichKey!', 'WhichKeyVisual', 'WhichKeyVisual!'] } " menu
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
" 文件树
" Plug 'Shougo/defx.nvim', { 'do': ':UpdateRemotePlugins' }
" 	Plug 'kristijanhusak/defx-icons'
" 	Plug 'kristijanhusak/defx-git'
Plug 'voldikss/vim-floaterm' " 浮动终端
Plug 'tyru/caw.vim' " 注释
" 函数导航
Plug 'liuchengxu/vista.vim'
" quick run
Plug 'skywind3000/asyncrun.vim'
" Debugger
" Plug 'puremourning/vimspector', {'do': './install_gadget.py --enable-c --enable-python'}
Plug 'ryanoasis/vim-devicons' " icon
" 多光标
Plug 'mg979/vim-visual-multi'
" 测速
" Plug 'tweekmonster/startuptime.vim'
" snippets
Plug 'honza/vim-snippets'
call plug#end()
let g:which_key_map = {}

" wikipedia
let g:vimwiki_list = [{'path': '~/Documents/vimwiki/',
                      \ 'syntax': 'markdown', 'ext': '.md'}]

" modules
" source $VIM_PATH/modules/defx.vim
source $VIM_PATH/modules/coc.vim

" debuger
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
" Quickfix window
let g:asyncrun_open = 6
" 命令结束后是否响铃
let g:asyncrun_bell = 1
let g:asyncrun_status = ''
let g:airline_section_error = airline#section#create_right(['%{g:asyncrun_status}'])
" fugitive
" The '@' sign is a separator to indicate following string is the parameters of 'make'.
command! -bang -nargs=* -complete=file Make AsyncRun -program=make @ <args>
command! -bang -bar -nargs=* Gpush execute 'AsyncRun<bang> -cwd=' .
          \ fnameescape(FugitiveGitDir()) 'git push' <q-args>

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
	\ 'coc-snippets',
	\ 'coc-vimlsp']

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
" Leaderf gtags --update
let g:Lf_GtagsAutoGenerate = 1
let g:Lf_Gtagslabel = 'native-pygments'

" markdown-preview
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

" indentLine
" If you want to highlight conceal color with your colorscheme, disable by
let g:indentLine_char_list = ['|', '¦', '┆', '┊']

so $VIM_PATH/modules/whichkey.vim
