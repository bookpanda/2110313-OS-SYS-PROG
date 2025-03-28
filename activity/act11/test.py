import requests


def myRead():
    req = requests.get(
        "https://mis.cp.eng.chula.ac.th/krerk/teaching/2022s2-os/status.php"
    )
    content = req.text.encode()
    return content


def myWrite(buf):
    raw = buf.split(":")
    checkInUrl = "https://mis.cp.eng.chula.ac.th/krerk/teaching/2022s2-os/checkIn.php"
    params = {"studentid": raw[0], "name": raw[1], "email": raw[2]}
    requests.post(checkInUrl, data=params)

    return len(buf)


def main():
    # print(myRead())
    print(myWrite("a:b:c"))


if __name__ == "__main__":
    main()
