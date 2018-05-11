import requests
from PIL import Image
from bs4 import BeautifulSoup
import io


def get_all_img_links(URL):

	req = requests.get(URL)
	img_links = []
	if req.status_code == 200:
		parser_obj = BeautifulSoup(req.content, "html.parser")
		img_tag_list = parser_obj.find_all("img")
		for img_tag in img_tag_list:
			img_links.append(img_tag["src"])
	return img_links

def download_images(url_list):
	for img_url in url_list:
		img_req = requests.get("https://www.express.com.pk/%s" % img_url,stream =True)
		i = Image.open(io.BytesIO(img_req.content))
		img_name = img_url.split("/")[-1]
		i.save("images/%s" % img_name)

def main():
	URL = "https://express.com.pk/"
	url_list = get_all_img_links(URL)
	download_images(url_list)

if __name__ == "__main__":
	main()
