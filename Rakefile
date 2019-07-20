require 'fileutils'

USERNAME  = 'my'
KEYBOARDS = {
  'planck' => ['ez'],
  'converter/usb_usb' => [nil],
}
QMK_DIR   = "#{__dir__}/qmk"
USER_DIR  = "#{QMK_DIR}/users/#{USERNAME}"

# TMK_DIR   = "#{__dir__}/tmk"

def keymap_dir(keyboard)
  "#{QMK_DIR}/keyboards/#{keyboard}/keymaps/#{USERNAME}"
end

task default: :install

desc 'Symlink keymap files into QMK source tree'
task :install do
  FileUtils.ln_s(File.expand_path('user', __dir__), USER_DIR, verbose: true) unless File.exist?(USER_DIR)

  KEYBOARDS.each_key do |keyboard|
    dest = keymap_dir(keyboard)
    FileUtils.ln_s(File.expand_path(keyboard, __dir__), dest, verbose: true) unless File.exist?(dest)
  end
end

desc 'Remove symlinks from QMK source tree'
task :uninstall do
  FileUtils.rm_r USER_DIR, verbose: true, force: true

  KEYBOARDS.each_key do |keyboard|
    FileUtils.rm_r keymap_dir(keyboard), verbose: true, force: true
  end
end

desc 'Remove build artifacts'
task :clean do
  Dir.chdir(QMK_DIR) { sh 'make clean' }
end

namespace :qmk do
  desc 'Install QMK dependencies'
  task :install do
    Dir.chdir(QMK_DIR) { sh 'util/qmk_install.sh' }
  end

  desc 'Update QMK firmware'
  task :update do
    Dir.chdir(QMK_DIR) do
      sh 'git pull --ff-only'
      sh 'make git-submodule'
    end
  end
end

desc 'Build all keymaps for CI'
task ci: :install do
  Dir.chdir(QMK_DIR) do
    KEYBOARDS.each do |keyboard, revisions|
      revisions.each do |revision|
        target = revision.nil? ? keyboard : "#{keyboard}/#{revision}"
        sh "make #{target}:#{USERNAME}"
      end
    end
  end

  # Dir.chdir(TMK_DIR) do
  #   Dir.chdir("converter/usb_usb") do
  #     sh "make"
  #   end
  # end
end

desc 'Build and install Planck EZ'
task planck: :ci do
  sh "wally-cli qmk/planck_ez_my.bin"
end

desc 'Build and install USB-USB Advantage2'
task advantage: :ci do
  sh "./dfu-wait.sh atmega32u4"
  sh "dfu-programmer atmega32u4 erase --force"
  # sh "dfu-programmer atmega32u4 flash qmk/converter_usb_usb_hasu_default.hex"
  sh "dfu-programmer atmega32u4 flash qmk/converter_usb_usb_hasu_my.hex"
  sh "dfu-programmer atmega32u4 reset"

  # Dir.chdir(TMK_DIR) do
  #   Dir.chdir("converter/usb_usb") do
  #     sh "make dfu"
  #   end
  # end
end
