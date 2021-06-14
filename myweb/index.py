from flask import Flask, render_template

web = Flask(__name__)


@web.route('/index.html')
def index():
    return render_template('index.html')


@web.route('/about.html')
def about():
    return render_template('about.html')


@web.route('/blog.html')
def blog():
    return render_template('blog.html')


@web.route('/work.html')
def work():
    return render_template('work.html')


@web.route('/contact.html')
def contact():
    return render_template('contact.html')


if __name__ == '__main__':
    web.run(host="0.0.0.0")
