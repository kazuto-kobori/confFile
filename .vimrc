"バックアップファイル(~)を作らない
set nobackup

"swpファイルを作らない
set noswapfile

"行番号を表示
set number

"現在の行を強調表示
"set cursorline

"ステータスラインを常に表示
set laststatus=2

"シンタックスハイライトの有効化
syntax on

"挿入モードにバックスペースで削除可
set backspace=indent,eol,start

"検索時大文字小文字を区別しない
set ignorecase

"ファイル末尾から先頭に移動して検索
set wrapscan

"インクリメンタル検索
set incsearch

"検索結果をハイライト表示
set hlsearch

"エラー時にビープを鳴らさない
set noerrorbells

"コマンドラインの高さ
set cmdheight=2

"自動インデントの幅
set shiftwidth=4

"タブの幅
set tabstop=4

"改行時に前の行のインデントを継続
set autoindent

"対応するカッコを強調
set showmatch

"スクロールの余裕を確保
set scrolloff=3

"インサートモードでjjと入力た場合はESCとみなす
inoremap jj <Esc>

"空白文字の表示
"set list

"空白文字の形式
"set listchars=tab:>-,eol:↲,extends:»,precedes:«
"空白 trail:-,

"空白文字の色変更
"hi NonText    ctermfg=241
"hi SpecialKey ctermfg=241

"Esc2回でハイライト解除
nmap <Esc><Esc> :nohlsearch<CR><Esc>

"カッコの補完とインデント
"inoremap {<Enter> {}<Left><CR><Esc><S-o>
"inoremap [ []<Left>
"inoremap ( ()<left>

"挿入中の自動折返しに日本語を対応
set formatoptions+=mM

"カーソル移動を表示行単位に
nnoremap j gj
nnoremap k gk

"色を 256 色に
"if $TERM == 'screen-256color' || $TERM == 'tmux-256color'
"    set t_Co=256
"endif

"TrueColor
if exists('+termguicolors')
  set termguicolors
endif

"背景色
set background=dark
"set background=light

"カラースキーム
if filereadable(expand("~/.vim/colors/ThemerVim.vim"))
  colo ThemerVim
endif

"ビープ音を止める
set belloff=all

"Vim 内部の文字コード
set encoding=utf-8

"ファイル書き込み時の文字コード
set fileencoding=utf-8

"ファイル読み込み時の文字コード
set fileencodings=utf-8,cp932,eucjp

" 特定の拡張子ではは tab をスペースとして扱う
autocmd BufNewFile,BufRead *.hs set expandtab
autocmd BufNewFile,BufRead *.py set expandtab
autocmd BufNewFile,BufRead *.ml set expandtab
autocmd BufNewFile,BufRead *.mly set expandtab
autocmd BufNewFile,BufRead *.mll set expandtab
autocmd BufNewFile,BufRead *.yaml set expandtab
autocmd BufNewFile,BufRead *.yaml set tabstop=2

" 削除した文字をヤンクしない
nnoremap x "_x
nnoremap s "_s
nnoremap c "_c

" クリップボードを共有
set clipboard+=unnamed

" MarkDown 用の syntax を修正
au BufRead,BufNewFile *.md set filetype=markdown
augroup update_markdown_syntax
  autocmd!
  autocmd FileType markdown syntax match markdownError '\w\@<=\w\@='
augroup END
