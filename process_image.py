import os
from PIL import Image

def compress_image_to_2mp(image_path):
    # 目标像素数为2MP
    target_pixels = 2 * 10**6
    
    with Image.open(image_path) as img:
        width, height = img.size
        current_pixels = width * height
        
        # 如果图片像素已小于2MP，则不进行压缩
        if current_pixels <= target_pixels:
            # 提示用户跳过压缩
            print(f"{image_path} 已经小于2MP，跳过压缩。")
            return
        
        # 计算新的尺寸，保持纵横比
        aspect_ratio = width / height
        new_width = int((target_pixels / aspect_ratio) ** 0.5)
        new_height = int(new_width / aspect_ratio)
        
        # 压缩图片
        resized_img = img.resize((new_width, new_height), Image.ANTIALIAS)
        
        # 覆盖原图片
        resized_img.save(image_path, quality=95)

def process_directory(directory):
    # 支持的图片格式
    supported_formats = ['jpg', 'jpeg', 'png', 'bmp', 'gif']
    
    # 遍历目录及其子目录
    for dirpath, _, filenames in os.walk(directory):
        for file_name in filenames:
            if any(file_name.lower().endswith(fmt) for fmt in supported_formats):
                print(f"处理 {os.path.join(dirpath, file_name)} 中...")
                compress_image_to_2mp(os.path.join(dirpath, file_name))

if __name__ == '__main__':
    # 指定要处理的根目录，这里设置为当前目录
    root_directory = '.'
    process_directory(root_directory)