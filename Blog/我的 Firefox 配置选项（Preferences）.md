# 我的 Firefox 配置选项（Preferences）

> 配置编辑器（即 about:config 页面）会列出名为“首选项”的 Firefox 设置项目，这些设置从 Firefox 用户配置文件中的 prefs.js 和 user.js 文件或程序的默认设置中读取。由于这些首选项属于高级设置项目，它们不会在 选项 面板中出现。
> 警告：修改这些高级设置有时会造成 Firefox 崩溃或其他奇怪的现象。请您仅在完全知晓自己在做什么或在遵从值得信赖的建议的情况下操作。
> [Firefox 的配置编辑器](https://support.mozilla.org/zh-CN/kb/about-config-editor-firefox)

在地址栏输入 `about:config` ，然后按回车，进入配置界面。

更加详实的 about:config 参数解释可以参考[About:config entries](http://kb.mozillazine.org/Firefox_:_FAQs_:_About:config_Entries)、[火狐参考与注册参数目录](https://docs.google.com/document/d/1jKbX_ZL7DyPa8XI2kagu5eO0kmdVAtOixdfqe8RRRJQ/pub)、[ghacks-user.js](https://github.com/ghacksuserjs/ghacks-user.js)。

以下适用于 Firefox 73.1 (Win 64 位) 国际版。

[TOC]

## 标签页

### 更改标签页最小宽度
`browser.tabs.tabMinWidth`

### 新建标签页在当前标签页的右侧

`browser.tabs.insertAfterCurrent`

### 书签内容在当前标签页的右侧打开

`browser.tabs.loadBookmarksInTabs`

### 在当前标签页的右侧打开

地址栏： `browser.urlbar.openintab`

搜索框： `browser.search.openintab`

### 关闭最后一个标签页时不关闭 Firefox

`browser.tabs.closeWindowWithLastTab`

### 转到上/下一页中保存的标签数

`browser.sessionhistory.max_total_viewers`

默认 -1（无限）

### 支持多标签页管理

使用 Ctrl 和 Shift

`browser.tabs.multiselect`

### 最大弹出窗口数

`dom.popup_maximum`

### 双击关闭标签页

`browser.tabs.closeTabByDblclick`

### 标签栏始终列出所有标签页

`browser.tabs.tabmanager.enabled`

## 地址栏与工具栏

### 地址栏网址推荐排序比重

|名称|初始值|
|-|-|
|places.frecency.bookmarkVisitBonus|75|
|places.frecency.defaultVisitBonus|0|
|places.frecency.downloadVisitBonus|0|
|places.frecency.embedVisitBonus|0|
|places.frecency.framedLinkVisitBonus|0|
|places.frecency.linkVisitBonus|100|
|places.frecency.permRedirectVisitBonus|50|
|places.frecency.redirectSourceVisitBonus|25|
|places.frecency.reloadVisitBonus|0|
|places.frecency.tempRedirectVisitBonus|40|
|places.frecency.typedVisitBonus|2000|
|places.frecency.unvisitedBookmarkBonus|140|
|places.frecency.unvisitedTypedBonus|200|

### 调整地址栏网址推荐数量

`browser.urlbar.maxRichResults`

### 当点击URL地址栏时，选择所有的文本

单击： `browser.urlbar.clickSelectsAll`

双击： `browser.urlbar.doubleClickSelectsAll`

### 在地址栏中自动添充URL地址

`browser.urlbar.autoFill`

根据本地浏览记录、书签

### 地址栏不隐藏 `http://`

`browser.urlbar.trimURLs`

### 在全屏模式下隐藏工具栏

`browser.fullscreen.autohide`

## 缓存

### 缓存大小

内存： `browser.cache.memory.capacity`
磁盘： `browser.cache.disk.capacity`

单位是 kb，设成 -1 则为自动调节

磁盘可以设置 `browser.cache.disk.smart_size.enabled` 来~~智能~~设置，现代计算机应该有1个G

### 启用

内存： `browser.cache.memory.enable`
磁盘： `browser.cache.disk.enable`

硬盘设为 false 且内存为 true 可将缓存从硬盘转移至内存，即禁用磁盘缓存，不建议

## 开发

### 自定义源代码查看编辑器

1. 将 `view_source.editor.external` 设为 `true`
2. 新建 `view_source.editor.path` 为你的编辑器路径

### 禁用 IPv6

`network.dns.disableIPv6`

校园网的各位不推荐

### 连接同一个服务器允许的最大持久连接数（可以启用多线程下载）

`network.http.max-persistent-connections-per-server`

代理服务器： `network.http.max-persistent-connections-per-proxy`

### 允许从本地载入资源

`security.fileuri.strict_origin_policy`

## 扩展

### 安装延迟时间

`security.dialog_enable_delay`

单位毫秒，默认等待1秒再安装

**警告：听说设置为0会有安全问题**

### 在 Mozilla 网站上启用扩展

**请确保所装扩展是你信任的**

`privacy.resistFingerprinting.block_mozAddonManager`

### 安装未签名扩展

`xpinstall.signatures.required`

## 杂项

### 实验项目更新时间

`app.normandy.run_interval_seconds`

### 同步所有首选项

参考[同步定制的首选项](https://support.mozilla.org/zh-CN/kb/%E5%90%8C%E6%AD%A5%E5%AE%9A%E5%88%B6%E7%9A%84%E9%A6%96%E9%80%89%E9%A1%B9)

`services.sync.prefs.dangerously_allow_arbitrary`

### 设置操作系统为暗色

新建整形 `ui.systemUsesDarkTheme` 为1

### 内置页面暗色调

`browser.in-content.dark-mode `

### 为隐私模式单独设置搜索引擎

`browser.search.separatePrivateDefault.ui.enabled`

### 启用视频画中画

`media.videocontrols.picture-in-picture.enabled`

### 启用自定义 CSS

`toolkit.legacyUserProfileCustomizations.stylesheets`

即开启 `UserChrome` 功能

### 单击鼠标中建粘贴剪切板内容

`middlemouse.paste`

### 搜索高亮强调动画

`findbar.modalHighlight`

### 搜索显示高亮

`findbar.highlightAll`

高亮数目现在支持1000个

### 保存到 pocket

`extensions.pocket.enabled`

鸡肋

### 启用不同身份容器

` privacy.userContext.enabled`

"File" -> "New Container Tab"

### 禁用网页自定义右键功能菜单（浏览器右键菜单在最前端）

`dom.event.contextmenu.enabled`

设为 true 后可用 shift + 右键实现

### 关闭快速查找

输入 `/` 或 `'（单引号，仅查找链接）` 进行查找

`accessibility.typeaheadfind.manual `

## 安全

### 禁用数字指纹（fingerprinting）

**禁用后有各种奇怪的问题**

`privacy.resistFingerprinting`

参考 [Security/Fingerprinting Wiki](https://wiki.mozilla.org/Security/Fingerprinting)

### 数据收集

通过 `about:telemetry` 可查看

**不推荐**

```
browser.newtabpage.activity-stream.feeds.telemetry
browser.newtabpage.activity-stream.telemetry
browser.ping-centre.telemetry
toolkit.telemetry.archive.enabled
toolkit.telemetry.bhrPing.enabled
toolkit.telemetry.enabled
toolkit.telemetry.firstShutdownPing.enabled
toolkit.telemetry.hybridContent.enabled
toolkit.telemetry.newProfilePing.enabled
toolkit.telemetry.reportingpolicy.firstRun
toolkit.telemetry.server # 清空
toolkit.telemetry.shutdownPingSender.enabled
toolkit.telemetry.unified
toolkit.telemetry.updatePing.enabled
experiments.activeExperiment
experiments.enabled
experiments.supported
network.allow-experiments
```

### 地理位置

`geo.enabled`

### 摄像头 / 麦克风

`media.navigator.enabled ` & `media.peerconnection.enabled`

### 在登录表单中查看密码

`signon.showAutoCompleteFooter`

### 非 HTTPS 第三方 cookies 在 Firefox 退出时候失效

`network.cookie.thirdparty.nonsecureSessionOnly`

### 对于 HTTP 非安全页面在地址栏显示不安全的字样

`security.insecure_connection_text.enabled` & `security.insecure_connection_text.pbmode.enabled`

### 支持不安全的 FTP 协议

`network.ftp.enabled`

### 混合内容中的 HTTP 资源更新为 HTTPS 资源

**这样会导致部分页面内容无法正常显示**

`security.mixed_content.upgrade_display_content`

### 同步功能

`identity.fxaccounts.enabled`

## 性能

请确保计算机是现代的

### 网页内容进程限制

禁用默认： `browser.preferences.defaultPerformanceSettings.enabled`

网页内容： `dom.ipc.processCount`

个人建议：有几 G 内存就设为几，-1 则为自动

### 其它内容进程限制

扩展（目前只能是单进程，即设为 1）： `dom.ipc.processCount.extension`

文件（file:// 协议，加载文件）： `dom.ipc.processCount.file`

大型页面： `dom.ipc.processCount.webLargeAllocation`

### 启用 WebGL

去 `about:support` 里查看 `Graphics` 部分

|名称|内容|
|-|-|
|webgl.force-enabled|强制启用|
|webgl.disabled|禁止使用|
|webgl.msaa-force|抗锯齿|
|pdfjs.enableWebGL|PDF JS启用WebGL|
|webgl.enable-webgl2|启用WebGL2|
|webgl.enable-draft-extensions|WebGL启用草稿扩展
|webgl.enable-privileged-extensions|WebGL启用特权扩展
|layers.acceleration.force-enabled|强制启用硬件渲染（无视黑名单/白名单）
|layers.acceleration.disabled|禁止使用|
|gfx.direct2d.force-enabled|在 Windows 平台上强制使用 D2D 加速页面内容渲染|
|gfx.direct2d.disabled|禁止使用|

### 启用 WebRender

使用 GPU 加速渲染

`gfx.webrender.enabled` & `gfx.webrender.all`

### 视频

不在视野范围内时挂起视频，禁止解码： `media.suspend-bkgnd-video.enabled`

强制启用硬解： `media.hardware-video-decoding.force-enabled`

图层加速： `layers.acceleration.force-enabled`

### CSS

Quantum CSS（Stylo）： `layout.css.servo.chrome.enabled`

保留显示列表（Retained Display List）： `layout.css.parsing.parallel` & `layout.display-list.retain` & `layout.display-list.retain.chrome`

### 非主线程绘制

`layers.omtp.enabled`

### JavaScript 启动字节码缓存

`dom.script_loader.bytecode_cache.enabled`

### 降低后台标签页的 CPU 占用

在音频视频播放、WebRTC 和 WebSocket 场景不使用

`dom.timeout.enable_budget_timer_throttling`

