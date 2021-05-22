" debuger
" let g:vimspector_enable_mappings = 'HUMAN'
nmap <F3> <Plug>VimspectorStop
nmap <F4> <Plug>VimspectorRestart
nmap <S-F5> <Plug>VimspectorContinue
nmap <F6> <Plug>VimspectorPause
nmap <F9> <Plug>VimspectorToggleBreakpoint
nmap <F10> <Plug>VimspectorStepOver
nmap <F11> <Plug>VimspectorStepInto

" quick run
" function! CompileRun() abort
" 	:AsyncRun -save=1 g++ -Wall -std=c++11 -O2 -Wno-unused-result "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"
" endfunction
" nnoremap <F12> :call CompileRun()<CR>
nnoremap <F1> :AsyncRun -save=1 g++ -Wall -std=c++11 -O2 -Wno-unused-result -g "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"<CR>
nnoremap <leader>lc :AsyncRun -save=1 g++ -Wall -std=c++11 -O2 -Wno-unused-result -g "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"<CR>
nnoremap <F12> :AsyncRun -mode=term -pos=right -raw -cwd=$(VIM_FILEDIR) "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"<CR>
nnoremap <leader>lr :AsyncRun -mode=term -pos=right -raw -cwd=$(VIM_FILEDIR) "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"<CR>
function Runcoder() " compile and run code
	if index(['c', 'cpp'], &ft) >= 0
		:AsyncRun -mode=term -pos=right -save=1 -cwd=$(VIM_FILEDIR) g++ -Wall -std=c++11 -O2 -Wno-unused-result -g "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe" && time "$(VIM_FILEDIR)/$(VIM_FILENOEXT).exe"
	endif
endfunction
nnoremap <F5> :call Runcoder() <CR>
inoremap <F5> <ESC> :call Runcoder() <CR>
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
nnoremap <F8> :call asyncrun#quickfix_toggle(6)<cr>

" coc-snippets
" Use <C-l> for trigger snippet expand.
imap <C-l> <Plug>(coc-snippets-expand)
" Use <C-j> for select text for visual placeholder of snippet.
vmap <C-j> <Plug>(coc-snippets-select)
" Use <C-j> for jump to next placeholder, it's default of coc.nvim
let g:coc_snippet_next = '<c-j>'
" Use <C-k> for jump to previous placeholder, it's default of coc.nvim
let g:coc_snippet_prev = '<c-k>'
" Use <C-j> for both expand and jump (make expand higher priority.)
imap <C-j> <Plug>(coc-snippets-expand-jump)
" Use <leader>x for convert visual selected code to snippet
xmap <leader>x  <Plug>(coc-convert-snippet)
" Make <tab> used for trigger completion, completion confirm, snippet expand and jump like VSCode.
" inoremap <silent><expr> <TAB>
"     \ pumvisible() ? coc#_select_confirm() :
"     \ coc#expandableOrJumpable() ? "\<C-r>=coc#rpc#request('doKeymap', ['snippets-expand-jump',''])\<CR>" :
"     \ <SID>check_back_space() ? "\<TAB>" :
"     \ coc#refresh()
" function! s:check_back_space() abort
"   let col = col('.') - 1
"   return !col || getline('.')[col - 1]  =~# '\s'
" endfunction
" let g:coc_snippet_next = '<tab>'

" coc-floaterm
nnoremap <LocalLeader>t :FloatermToggle<CR>
nnoremap <LocalLeader>n :FloatermNew
nnoremap <LocalLeader>j :FloatermNext<CR>
nnoremap <LocalLeader>k :FloatermPrev<CR>

" coc-pairs
inoremap <silent><expr> <cr> pumvisible() ? coc#_select_confirm() : "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"

" Leaderf
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

" accelerated-jk
nmap j <Plug>(accelerated_jk_gj)
nmap k <Plug>(accelerated_jk_gk)

" Graph your Vim undo tree in style.
nnoremap <leader>fh :MundoToggle<CR>

" markdown-preview
nmap <leader>lp <Plug>MarkdownPreviewToggle

" Vista
nnoremap <F2> <ESC>:Vista!!<CR>
inoremap <F2> <ESC>:Vista!!<CR>

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
