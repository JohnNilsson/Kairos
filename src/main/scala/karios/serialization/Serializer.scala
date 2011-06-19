package karios.serialization

import kairos._

import java.nio.channels.WritableByteChannel
import java.nio.channels.ReadableByteChannel

trait Serializer[T <: Message] {
  def serialize(message: T, destination: WritableByteChannel)
}

trait Deserializer[T <: Message] {
  def deserialize(message: T, source: ReadableByteChannel)
}