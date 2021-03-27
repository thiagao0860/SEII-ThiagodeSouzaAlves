import os

os.chdir('/home/thiago/Desktop/teste/')
for f in os.listdir():

    file_name, file_ext = os.path.splitext(f)

    f_title, f_course, f_number = file_name.split('-')

    f_title = f_title.strip()
    f_course = f_course.strip()
    f_number = f_number.strip()[1:].zfill(2)

    print('{}-{}{}'.format(f_number, f_title.strip(), file_ext.strip()))
    new_name = '{}-{}{}'.format(f_number, f_title, file_ext)
    os.rename(file_name, new_name)

