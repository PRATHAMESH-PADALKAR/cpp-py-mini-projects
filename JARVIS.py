import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[0].id) 

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("good morning sir")

    elif hour>=12 and hour<18:
        speak("good afternoon sir")

    else:
        speak("good evening sir")
    
    speak("i am JARVIS. please tell me how can i help you?")


def takeCommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print('listening....')
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing....")
        query = r.recognize_google(audio, language='en-in')
        print(f"user said: {query}\n")

    except Exception as e:
        #print(e)
        speak('please say that again ....')
        return "none"
    return query

def sendEmail(to , content):
    server = smtplib.SMTP('smtp.gmail.com',587)
    server.ehlo()
    server.starttls()
    server.login("padalkarprathamesh00@gmail.com","Sawantpark@123")
    server.sendmail('padalkarprathamesh00@gmail.com', to , content)
    server.close()
       
if __name__ == "__main__":
    wishMe()
    while True:
        query = takeCommand().lower()  

        if 'wikipedia' in query:
            speak('searching Wikipedia...')
            query = query.replace('wikipedia',"")
            results = wikipedia.summary(query , sentences = 2)
            speak("According to wikipedia")
            print(results)
            speak(results)

        elif 'open youtube' in query:
            webbrowser.open('youtube.com')

        elif 'open google' in query:
            webbrowser.open('google.com')

        elif 'open hamster' in query:
            webbrowser.open('xhamster16.desi')

        elif 'open stack overflow' in query:
            webbrowser.open('stackoverflow.com')

        elif 'play music' in query:
            """music_dir =  'D:\\Space Age Hustle - Squadda B.mp3'
            songs = os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[0]))"""

        elif "time" in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"sir,the time is {strTime}") 
            
        elif 'open v s code' in query:
            codePath = "C:\\Users\\hp\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
            os.startfile(codePath)

        elif "email to Prathamesh" in query:
            try:
                speak("what should i say?")
                content = takeCommand()
                to = "padalkarprathamesh00@gmail.com"
                sendEmail(to, content)
                speak("email has been sent")
            except Exception as e:
                print(e)
                speak("sorry padya bhai , iam not able to send the email" )