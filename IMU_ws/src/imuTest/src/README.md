### 通信方法
無線接続の場合、ifconfig でwlanの最初のinetのipアドレスを確認する。

##### マスタ側
export ROS_MASTER_URI=http://192.168.1.41(自分のip):11311
roscore

#### ノード側
export ROS_MASTER_URI=http://192.168.1.41(自分のip):11311
export ROS_IP = 192.168.1.41(自分のip、全部のノードでやっておく)

#### 注意!
ナゼか知らんが
[registerPublisher] Failed to contact master at (マスターIP)
export ROS_MASTER_URI=http://localhost:11311
export ROS_HOSTNAME=localhost
が無いか確認。あれば消しておく。パス大嫌い！

ちなみにscpコマンドとかでファイル転送するならパッケージだけにしておく。wsごと移すとこれまたパス関係で狂う。こっちはエラー文出るけど...