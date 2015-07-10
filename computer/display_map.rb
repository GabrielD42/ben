require 'yaml'
require 'socket'

def setup
  @config = YAML.load(File.read('config.yaml'))
  size @config['screen']['width'], @config['screen']['width']
  frame.setResizable @config['screen']['resizable']
end

def draw
  begin
    socket = TCPSocket.open @config['connection']['host'],
                            @config['connection']['port']
    @pos = Marshal.load socket.gets
    @map = Marshal.load socket.gets
    socket.close
  rescue
    return
  end
  return unless @pos && @map
  # p @pos
  scale_x = width / @map.first.length
  scale_y = height / @map.length
  @map.each_with_index do |row, y|
    row.each_with_index do |cell, x|
      fill map(1 - cell, 0, 1, 0, 255)
      rect x * scale_x, y * scale_y, scale_x, scale_y
    end
  end
  fill 0, 0, 255
  ellipse (@pos[:x] - 0.5) * scale_x, (@pos[:y] - 0.5) * scale_y, scale_x * 0.75, scale_y * 0.75
end
