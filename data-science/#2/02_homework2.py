'''
데이터사이언스 2주차 과제2

score.xlsx 파일을 mysql 데이터베이스 안에 score 테이블로 생성
'''

import pandas as pd
import pymysql

xl_file = './score.xlsx'
df = pd.read_excel(xl_file)

conn = pymysql.connect(host='localhost', user='datascience', password='datascience', db='university')
curs = conn.cursor(pymysql.cursors.DictCursor)

sql = '''CREATE TABLE if not exists score (
sno int primary key, 
attendance float,
homework float,
discussion int,
midterm float,
final float,
score float,
grade varchar(20))'''

curs.execute(sql)

sql = '''INSERT INTO score 
(sno, attendance, homework, discussion, midterm, final, score, grade)
VALUES (%s, %s, %s, %s, %s, %s, %s, %s) '''

for i in range(len(df)):
    curs.execute(sql, tuple(df.values[i]))

conn.commit()

curs.close()
conn.close()