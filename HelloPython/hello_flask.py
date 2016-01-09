#!/usr/bin/env python3
# coding utf-8

from flask import Flask
from flask import jsonify
app = Flask(__name__)

@app.route('/')
def index():
    return 'Index Page'

@app.route('/hello')
def hello():
    return 'Hello World'

@app.route('/user/<username>')
def show_user_profile(username):
    return 'hello {0}'.format(username)

@app.route('/json')
def show_json_data():
    return jsonify({"age": 24, "name": "hatlonely", "skill": ["java", "c++"], "email": "hatlonely@gmail.com"})

if __name__ == '__main__':
    app.run(port=5000)
