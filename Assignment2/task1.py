import requests
from bs4 import BeautifulSoup
import io
import os
import datetime


def get_all_href_links(URL):

    req = requests.get(URL)
    href_links = []
    if req.status_code == 200:
        soup = BeautifulSoup(req.content, "lxml")
        pre_tag = soup.find("pre")
        a_tag_list = pre_tag.findChildren()[1:3]
        #For Log File
        str1 = str(datetime.datetime.now().strftime("%y-%m-%d-%H-%M"))
        str1 += " Total Qari " + str(len(a_tag_list)) + "\n"
        writeInLog(str1)
        return a_tag_list


def get_all_audio(URL):

    req = requests.get(URL)
    href_links = []
    if req.status_code == 200:
        soup = BeautifulSoup(req.content, "lxml")
        pre_tag = soup.find("pre")
        a_tag_list = pre_tag.findChildren()
        return a_tag_list[len(a_tag_list)-27:len(a_tag_list)]


def download_audio(a_tag_list, URL):
    count = 1
    for a_tag in a_tag_list:
        href_link = a_tag['href']
        writeInLog(str(datetime.datetime.now().strftime("%y-%m-%d-%H-%M")) + " Start Processing " + str(count) + " of " + str(len(a_tag_list)) + "\n")   # For Log FIle
        writeInLog(str(datetime.datetime.now().strftime("%y-%m-%d-%H-%M")) + " " + str(href_link)[:-1] + "\n")   #For Log FIle
        os.system("mkdir "+ href_link)
        audio_list1 = get_all_audio(URL + "/%s" %href_link )
        audio_list = audio_list1[:3]
        for audio in audio_list:
            writeInLog(str(datetime.datetime.now().strftime("%y-%m-%d-%H-%M")) + " " + str(href_link)[:-1] + " " + audio['href'] + " START" + "\n")  # For Log FIle
            d_audio = requests.get(URL + "/" + href_link + "/" + audio["href"])
            with open(href_link + audio['href'], 'wb') as writefile:
                writefile.write(d_audio.content)
            writeInLog(str(datetime.datetime.now().strftime("%y-%m-%d-%H-%M")) + " " + str(href_link)[:-1] + " " + audio['href'] + " END"+ "\n")  # For Log FIle
        writeInLog(str(datetime.datetime.now().strftime("%y-%m-%d-%H-%M")) + " Merging Files of " + str(href_link)[:-1] + " START "+ "\n")  # For Log FIle
        os.system("mp3wrap " + href_link + "final.mp3 " + href_link + "*.mp3")
        writeInLog(str(datetime.datetime.now().strftime("%y-%m-%d-%H-%M")) + " Merging Files of " + str(href_link)[:-1] + " END "+ "\n")  # For Log FIle
        count+=1


def writeInLog(strToWrite):
    file = open("log.txt", "a+")
    file.write(strToWrite)
    file.close()


def main():
    URL = "https://download.quranicaudio.com/quran/"
    a_tag_list = get_all_href_links(URL)
    download_audio(a_tag_list, URL)

if __name__ == "__main__":
    main()