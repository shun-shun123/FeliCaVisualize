# coding: utf-8
from httpClient import HttpClient
from scrape import Pictures

httpClient = HttpClient()
scrapePictures = Pictures("長岡京駅")

httpClient.GET()
scrapePictures.scrapePictures()
