# C++ ディレクトリ
このディレクトリはMATLAB関数のC++移植を目的とした作業領域です。

## ディレクトリ構成
```
cpp/
├── CMakeLists.txt     # CMakeビルド設定ファイル
├── README_cpp.md      # このファイル
├── include/           # ヘッダーファイル
│   └── hello.h        # Hello, World! 関数の宣言
├── src/               # ソースファイル
│   └── hello.cpp      # Hello, World! 関数の実装
└── test/              # テストファイル
    └── main.cpp       # メイン実行ファイル
```

## 必要な環境
- CMake 3.10 以上
- C++17 対応コンパイラ (GCC, Clang, MSVC など)

## ビルド方法

### 1. ビルドディレクトリの作成
```bash
mkdir build
cd build
```

### 2. CMakeの設定
```bash
cmake ..
```

### 3. ビルドの実行
```bash
cmake --build .
```

## 実行方法
ビルドが完了すると、`sparkng_test` という実行ファイルが生成されます。

```bash
# Linux/macOS の場合
./sparkng_test

# Windows の場合
sparkng_test.exe
```

実行すると "Hello, World!" が出力され、続いてLFModelテストの結果が表示されます。

## LFModelテスト例追加

### 概要
`test/main.cpp` にLFModel関数のテスト例が追加されました。このテストでは、教科書的なLFモデルのパラメータを使用して `openTermk` 関数を呼び出し、時間軸上の複数点での計算結果を出力します。

### 使用パラメータ
- `tp` (Peak time): 0.2
- `te` (End time): 0.6  
- `ta` (Attack time): 0.05
- `tc` (Cycle time): 1.0
- `Twor` (World reference time): 0.01

### 時間軸
- 範囲: 0.0 ～ 1.0
- 刻み: 0.01
- 出力: 約10点のサンプル値

### 実行結果の形式
```
LFModel openTermk test results:
Parameters: tp=0.2, te=0.6, ta=0.05, tc=1.0, Twor=0.01

LFModel openTermk value: t=0.0, result=...
LFModel openTermk value: t=0.1, result=...
...
```

## テストの実行
CMakeのテスト機能を使用してテストを実行できます：

```bash
ctest
```

## ファイルの説明

### CMakeLists.txt
- プロジェクト全体のビルド設定
- ライブラリとテスト実行ファイルの定義
- C++17 標準の設定

### include/hello.h
- `say_hello()` 関数の宣言
- インクルードガード付きヘッダーファイル

### src/hello.cpp
- `say_hello()` 関数の実装
- "Hello, World!" を標準出力に表示

### test/main.cpp
- メイン関数の実装
- `say_hello()` 関数を呼び出すテストプログラム
- **新規追加**: LFModel関数のテスト例
  - `lfmodel.h` ヘッダのインクルード
  - 教科書的なパラメータでのLFモデルテスト
  - `openTermk` 関数の呼び出しと結果出力

## トラブルシューティング

### CMakeが見つからない場合
CMakeがインストールされていることを確認してください：

```bash
cmake --version
```

### コンパイルエラーが発生する場合
コンパイラがC++17に対応していることを確認してください。古いコンパイラを使用している場合は、CMakeLists.txtの`CMAKE_CXX_STANDARD`を調整してください。
