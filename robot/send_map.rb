require 'forwardable'
require 'thread'
require 'socket'
require 'pp'

class Map
  def initialize(map, prior = 0.5)
    @map = map
    @prior = prior
  end

  def self.unknown_map(width, height, prior = 0.5)
    # weird syntax so that each element is a new object
    Map.new((0..width).collect { (0..height).collect { :unknown } }, prior)
  end

  def self.random_map(width, height, prior = 0.5)
    Map.new((0..width).collect { (0..height).collect { rand } }, prior)
  end

  extend Forwardable
  def_delegators :@map, :[], :[]=, :each
  include Enumerable

  def width
    @map.length
  end

  def height
    @map.first.length
  end

  def to_a
    @map.map do |row|
      row.map do |cell|
        case cell
        when 0..1     then cell
        when :unknown then @prior
        when :empty   then 0
        when :full    then 1
        end
      end
    end
  end
end

class VirtualRobot
  def initialize(map, x, y)
    @pos = { x: x, y: y }
    @full_map = map
    # @current_map = Map.unknown_map @full_map.width, @full_map.height
    @current_map = Map.random_map @full_map.width, @full_map.height
  end

  attr_accessor :pos

  def map
    @current_map
  end
end

robot = VirtualRobot.new Map.random_map(9, 9), 6, 5

Thread.new do
  server = TCPServer.open(2000)
  loop do
    client = server.accept
    # p robot.pos
    client.puts Marshal.dump robot.pos
    client.puts Marshal.dump robot.map.to_a
    client.close
    # robot.map[rand(0...robot.map.width)][rand(0...robot.map.height)] = rand
  end
end

loop do
  robot.pos[:x] += 1
  # 100.times {}
  sleep 1
  robot.pos[:y] += 1
  # 100.times {}
  sleep 1
  robot.pos[:x] -= 1
  # 100.times {}
  sleep 1
  robot.pos[:y] -= 1
  # 100.times {}
  sleep 1
end
