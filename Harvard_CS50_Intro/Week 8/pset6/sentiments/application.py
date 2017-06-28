from flask import Flask, redirect, render_template, request, url_for

from analyzer import Analyzer
import os
import sys
import nltk
from termcolor import colored
import helpers

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "")
    if not screen_name:
        return redirect(url_for("index"))

    # absolute paths to lists
    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")
    
    # instantiate analyzer
    analyzer = Analyzer(positives, negatives)

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name)
    if not tweets:
        return redirect(url_for("index"))        

    score = 0
    index = 0
    positive = 0
    negative = 0
    neutral = 0
    tokenizer = nltk.tokenize.TweetTokenizer()
    for tweet in tweets:
        tokens = tokenizer.tokenize(tweet)
        for token in tokens:
            score += analyzer.analyze(token)
            
        if score > 0.0:
            positive += 1
        elif score < 0.0:
            negative += 1
        else:
            neutral += 1
            
        score = 0
        index += 1    
    
    total = positive + negative + neutral
    
    
    positive, negative, neutral = 100 * positive / total, 100 * negative / total, 100 * neutral / total

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
