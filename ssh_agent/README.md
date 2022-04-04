## 使い方

* `sssh` コマンドで ssh-agent を開始、秘密鍵を登録
* bash を終了すると ssh-agent が終了

## インストール

```
cp -ai $HOME/.bashrc{,.old}
cat << '_EOF_' >> $HOME/.bashrc
# ssh_agent
ssh_agent_file="$HOME/.ssh/ssh_agent"
[ -f $ssh_agent_file ] && source $ssh_agent_file &> /dev/null
if ! ssh-add -l &> /dev/null; then
  unset SSH_AUTH_SOCK &> /dev/null
  unset SSH_AGENT_PID &> /dev/null
fi
unset ssh_agent_file

if [ -f ~/.ssh/ssh_agent.sh ]; then
    alias sssh=". ~/.ssh/ssh_agent.sh"
fi
# ssh_agent
_EOF_
ln -s $HOME/git/confFile/ssh_agent/ssh_agent.sh $HOME/.ssh
```

* ssh_agent の `<key_file>` を編集
