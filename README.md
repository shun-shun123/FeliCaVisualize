# FeliCaVisualize(2018/08)

## アプリの説明(Explanatin of this app)
Felicaを利用した交通系ICカードをandriodアプリで読み取り解析を行った後、サーバに送信し、そのデータをGETしデータビジュアライゼーションを行うメディアアート作品となっています。

読み取る交通系ICカードによって描画の結果が変わってくることから、アートとしての非同一性。

そして、交通系ICカードをタッチするというインタラクションをトリガーに描画を始めるというインタラクション性を重要視して開発しました。

ダミーデータはoFのdataフォルダに格納しているので、そのままappを起動して頂けると結果が観れると思います。

This proj is a media-art which visualizes the information of Felica IC card. After scaning IC card data, by using androidApp, the data is sent to a server which is developed by Google API. Finaly scrap the data by using python and visualize the data in openFrameworks proj.

# 環境(Environment)
* MacOS mojave
* Xcode 10.2.1
* openFrameworks0.10.1

