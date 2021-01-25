/*
 *  "Miscellaneous Utility Library" Software Licence
 * 
 *  Version 1.0
 * 
 *  Copyright (c) 2004-2008 Jon Skeet and Marc Gravell.
 *  All rights reserved.
 * 
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 * 
 *  1. Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 * 
 *  2. Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in the
 *  documentation and/or other materials provided with the distribution.
 * 
 *  3. The end-user documentation included with the redistribution, if
 *  any, must include the following acknowledgment:
 * 
 *  "This product includes software developed by Jon Skeet
 *  and Marc Gravell. Contact skeet@pobox.com, or see 
 *  http://www.pobox.com/~skeet/)."
 * 
 *  Alternately, this acknowledgment may appear in the software itself,
 *  if and wherever such third-party acknowledgments normally appear.
 * 
 *  4. The name "Miscellaneous Utility Library" must not be used to endorse 
 *  or promote products derived from this software without prior written 
 *  permission. For written permission, please contact skeet@pobox.com.
 * 
 *  5. Products derived from this software may not be called 
 *  "Miscellaneous Utility Library", nor may "Miscellaneous Utility Library"
 *  appear in their name, without prior written permission of Jon Skeet.
 * 
 *  THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 *  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *  IN NO EVENT SHALL JON SKEET BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE. 
 */

namespace ZHM.Common.IO.Conversion
{
	/// <summary>
	/// Implementation of EndianBitConverter which converts to/from big-endian
	/// byte arrays.
	/// </summary>
	public sealed class BigEndianBitConverter : EndianBitConverter
	{
		/// <summary>
		/// Indicates the byte order ("endianness") in which data is converted using this class.
		/// </summary>
		/// <remarks>
		/// Different computer architectures store data using different byte orders. "Big-endian"
		/// means the most significant byte is on the left end of a word. "Little-endian" means the 
		/// most significant byte is on the right end of a word.
		/// </remarks>
		/// <returns>true if this converter is little-endian, false otherwise.</returns>
		public override bool IsLittleEndian()
		{
			return false;
		}

		/// <summary>
		/// Indicates the byte order ("endianness") in which data is converted using this class.
		/// </summary>
		public override Endianness Endianness => Endianness.BigEndian;

        /// <summary>
		/// Copies the specified number of bytes from value to buffer, starting at index.
		/// </summary>
		/// <param name="p_Value">The value to copy</param>
		/// <param name="p_Bytes">The number of bytes to copy</param>
		/// <param name="p_Buffer">The buffer to copy the bytes into</param>
		/// <param name="p_Index">The index to start at</param>
		protected override void CopyBytesImpl(long p_Value, int p_Bytes, byte[] p_Buffer, int p_Index)
		{
			var s_EndOffset = p_Index + p_Bytes - 1;
			
            for (var i = 0; i < p_Bytes; ++i)
			{
				p_Buffer[s_EndOffset - i] = unchecked((byte) (p_Value & 0xff));
				p_Value >>= 8;
			}
		}
		
		/// <summary>
		/// Returns a value built from the specified number of bytes from the given buffer,
		/// starting at index.
		/// </summary>
		/// <param name="p_Buffer">The data in byte array format</param>
		/// <param name="p_StartIndex">The first index to use</param>
		/// <param name="p_BytesToConvert">The number of bytes to use</param>
		/// <returns>The value built from the given bytes</returns>
		protected override long FromBytes(byte[] p_Buffer, int p_StartIndex, int p_BytesToConvert)
		{
			long s_Ret = 0;
			
            for (var i = 0; i < p_BytesToConvert; ++i)
			    s_Ret = unchecked((s_Ret << 8) | p_Buffer[p_StartIndex+i]);

            return s_Ret;
		}
	}
}
