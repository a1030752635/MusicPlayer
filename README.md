# MuePlayer - Qt音乐播放器

MuePlayer是一个基于Qt框架开发的音乐播放器项目，主要用于学习和实践Qt的基础功能，包括界面设计、自定义控件、音乐管理、播放控制等功能。

![](https://gitee.com/UtoCoo/MuePlayer/raw/master/MuePlayer.png)

![](https://gitee.com/UtoCoo/MuePlayer/raw/master/LrcPage.png)

## 界面基础

### 窗口设置
项目采用无边框窗口设计，通过`setWindowFlag(Qt::FramelessWindowHint)`去掉了默认的标题栏，并使用`setAttribute(Qt::WA_TranslucentBackground)`设置背景半透明效果，营造现代化的界面风格。

### 窗口拖拽功能
由于去掉标题栏后窗口无法正常拖拽，项目通过重写鼠标事件来实现窗口拖拽：
- 在`mousePressEvent`中拦截鼠标左键点击，记录鼠标与窗口左上角的距离差
- 在`mouseMoveEvent`中利用相对位置不变的原理实现窗口跟随鼠标移动

### 视觉效果
使用`QGraphicsDropShadowEffect`为窗口添加阴影效果，通过设置阴影偏移、颜色和模糊半径来增强视觉层次感。

### QSS样式设计
项目大量使用QSS进行界面美化，包括：
- 类型选择器、ID选择器、并集选择器等多种选择器的运用
- 子类选择器用于选择特定控件的子元素
- 伪类选择器实现hover、pressed等交互状态
- 边框圆角、背景颜色等属性设置

### 资源管理
采用Qt的qrc资源文件机制，将图片、音频等二进制资源以C++代码形式编译到exe中，确保程序不依赖外部文件。

## 自定义控件

### 左侧按钮控件(BtForm)
设计了带有音乐播放动画的按钮控件：
- 使用四个细长条形状的QLabel实现播放动画效果
- 通过`QPropertyAnimation`实现动画，支持关键帧设置、循环播放等
- 实现自定义信号机制，按钮点击后发射信号通知主界面切换页面内容

### 推荐页面控件
- **RecBox**: 推荐区域容器控件
- **RecBoxItem**: 单个推荐项控件
- 支持上下布局切换，可根据需要隐藏部分布局管理器

### 页面管理
使用`QStackedWidget`实现多页面切换：
- Page1：推荐页面，使用`QScrollArea`实现滚动显示
- Page2：电台页面
- Page3：音乐页面，包含CommonPage和ListItemBox等组件

### 进度条控件(MusicSlider)
创新的双层QFrame设计：
- 底层白色QFrame作为背景
- 上层绿色QFrame作为进度指示器
- 通过动态调整上层QFrame大小来显示播放进度
- 支持拖拽seek功能

### 音量控件(VolumeTool)
独立的弹出式音量控制器：
- 采用`Qt::Popup`属性实现弹窗效果
- 使用`mapToGlobal`计算弹出位置
- 通过`QPainter`绘制三角形连接样式
- 支持鼠标拖拽调节音量

## 音乐管理

### Music类
面向对象的单首歌曲管理：
- 使用`QMediaPlayer`的`metaData("Title")`功能提取歌曲信息
- 通过`QUuid::createUuid().toString()`生成唯一的musicID
- 支持歌曲标题、路径等基本信息管理
- 包含收藏状态(isLike)等扩展属性

### MusicList类
程序中所有歌曲的集中管理：
- 管理所有Music对象的集合
- 提供`addMusicByUrl`方法将URL转换为Music对象
- 实现了对C++11范围for循环的支持，通过定义iterator、begin()、end()方法
- 支持不同页面的音乐分类管理

### 音乐分类系统
针对三个不同页面实现音乐分类：
- 本地音乐页面：直接插入所有导入的音乐
- 喜欢页面：根据Music的isLike属性进行过滤
- 历史播放页面：记录播放历史
- 使用`QVector<QString> musicListOfPage`存储各页面的音乐ID列表

### 文件导入功能
通过`QFileDialog`实现音乐文件导入：
- 设置为打开模式和多文件选择模式
- 使用MIME类型过滤器限制文件格式
- 返回`QList<QUrl>`供后续处理

## 音乐播放

### QMediaPlayer核心功能
- 使用`setMedia(QMediaContent)`加载音乐文件
- 通过`metaData()`获取歌曲元信息
- 监听`stateChanged`信号实现播放状态同步
- 支持音量控制和静音功能

### QMediaPlaylist播放列表
- 支持多种播放模式：随机播放(Random)、循环播放(Loop)等
- 通过`setPlaybackMode`设置播放模式
- 提供上一曲、下一曲的标准控制接口
- 与QMediaPlayer联动实现完整的播放控制

### 播放控制逻辑
- 播放/暂停按钮通过监听QMediaPlayer状态变化自动更新图标
- 时间显示通过`durationChanged`和`positionChanged`信号实现
- 进度条拖拽通过计算比例控制播放位置
- 音量控制采用事件过滤器处理鼠标拖拽

### 时间显示系统
- 使用`durationChanged`信号获取歌曲总时长
- 通过`positionChanged`信号实时更新播放进度
- 采用QString占位符`.arg()`格式化时间显示

## LRC歌词设计

### 歌词页面实现
项目包含专门的LRC歌词显示页面，支持歌词随播放进度同步显示功能。歌词系统与音乐播放紧密集成，能够根据当前播放位置高亮显示对应歌词行。

### 歌词显示问题处理
在开发过程中遇到歌词显示不全和移动无响应的问题，最终发现是由于阴影圆角半径设置过大导致的渲染异常。

## 其他问题

### 数据持久化
- 使用SQLite数据库存储音乐信息和用户设置
- 通过`QSqlDatabase`和`QSqlQuery`实现数据库操作
- 支持预处理语句和参数绑定，确保数据安全

### 重复音乐处理
- 使用`QSet`存储音乐文件路径，避免同一首歌曲重复添加
- 在程序启动时初始化QSet，防止重启后重复导入
- 通过路径对比而非随机UID进行重复检测

### 系统集成功能
- **托盘图标**: 使用`QSystemTrayIcon`实现系统托盘显示
- **右键菜单**: 通过`QMenu`提供托盘右键操作
- **单实例运行**: 利用共享内存机制防止程序多次启动

### 窗口控制
- 支持最小化功能，禁用最大化按钮
- 通过控制变量防止BtForm误触发窗口拖拽
- 实现自定义窗口图标设置

### 调试和优化
- 添加大量调试信息输出，便于问题定位
- 实现动画状态控制，支持多个BtForm的动画显示
- 优化事件处理逻辑，避免意外的界面操作

## 项目总结

MuePlayer项目是一个很好的Qt基础功能学习项目，涵盖了界面设计、自定义控件开发、多媒体播放、数据库操作等多个方面。通过这个项目可以深入理解Qt的信号槽机制、事件系统、QSS样式表、资源管理等核心概念，为进一步学习Qt高级功能打下坚实基础。
