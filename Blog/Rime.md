# Rime

[TOC]

谨以此文，纪念一下我用 Rime 时踩过的坑。

欢迎 star 我的配置 [myRime](https://github.com/ASC8384/myRime)。

## 编译

### librime

参考 [Build dependencies](https://github.com/rime/librime#build-dependencies)。

发现 libboost 最好装 `libboost-all-dev`，如果不行就装`libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev`试试。

发现 libglog 不装不行，得用`libgoogle-glog-dev`。

发现 libgtest 不装也不行。

编译用了 10 分钟，机子不行呀。

### librime-lua

这是 rime 的一个插件，主要提供了 lua 的支持。

如果有形如 `error creating translator: 'lua_translator'` 的报错，可以安装一下。

```bash
cd $PATH_TO_RIME_SOURCE # librime 
bash install-plugins.sh hchunhui/librime-lua # git clone https://github.com/hchunhui/librime-lua.git
sudo apt install liblua5.3-dev # pkg-config --list-all | grep lua
make merged-plugins # 这次进步了，只编译了 9 分钟。
sudo make install
```

在 `ibus_rime.yaml` 里添加:

```yaml
plugins:
  - librime-lua.so

modules:
  - lua
```

重启生效。
