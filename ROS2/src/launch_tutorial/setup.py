import os
from glob import glob
from setuptools import setup


package_name = 'launch_tutorial'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'),  # 这两行是添加launch 文件夹
            glob(os.path.join('launch', '*.launch.py'))),
        (os.path.join('share', package_name, 'config'), # 这两行是添加 config 文件夹
            glob(os.path.join('config', '*.yaml'))),],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='xiaochen',
    maintainer_email='zuqing.xie@greenteam-stuttgart.de',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        ],
    },
)
