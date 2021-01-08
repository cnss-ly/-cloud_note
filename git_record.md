# Git 

## Basic operation

### Initialize

```shell
git config --global user.name "username" #用户名
git config --global user.email "email" #邮箱
ssh-keygen -t rsa -C "my email" #填写email地址，然后一直“回车”
chmod 700 -R .ssh
cd ~/.ssh
chmod 600 *
复制公钥到github
ssh -T git@github.com #测试连接
git init #初始化一个本地仓库
```
###  Modify the remote warehouse

```shell
git clone "url" #将远端仓库克隆到本地
		case: git clone git@github.com:cnss-ly/cloud_note.git
git pull #拉取远端仓库以更新本地仓库
git branch "Branch name" #新建名为“Branch name”的分支
git checkout "Branch name" #切换到名为“Branch name”的分支
git add  "file/folder name" #添加本地仓库没有的文件或文件夹
git commit -m "modified content" #提交更改到本地仓库
git commit -a -m "modified content" #自动添加所有文件或文件夹修改并提交到本地仓库，但无法提交增添新文件的修改。
git checkout matser #切换到主分支
git merge "Branch name" #合并主分支和名为“Branch name”分支的冲突
git push #推送本地仓库到远端
```

### Branch control

```shell
git branch #查看本地分支
git branch -a #查看远程分支
git branch "Branch name" #创建分支"Branch name"
git checkout "Branch name" #切换到"Branch name"
git checkout -b "Branch name" #创建并切换到"Branch name"
git branch -d "Branch name" #删除分支
git switch "Branch name" #切换到"Branch name" ,与checkout可相互替换
git switch -c "Branch name" #创建并切换到"Branch name",与checkout -b可相互替换
```

### Version control

```shell
git reset --hard "version code" #回退到版本号所对应的版本
git reset --hard HEAD^ #回退到当前版本的上一版本,HEAD^^则表示上上版本,以此类推
git log #查看版本日志,显示从最近到最远的提交日志
git reflog #查看使用过的git命令,可以得到当前版本以后的版本
```

日后添加各命令详细介绍

### git stash

```shell
git stash #储藏未提交的更改
git stash pop #取出最近一次储藏

git stash save stash_name #储藏且命名stash_name
git stash list #stash列表,展示所有储藏，格式stash@{namber}
stash@{0},stash@{1},...
git stash pop stash@{number} #取出指定stash
```



