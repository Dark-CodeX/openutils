pkgname="openutils-chunkio"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="CHUNKIO : The Performant I/O Library"
arch=("x86_64" "i686")
conflicts=('openutils-chunkio')
depends=(gcc)
license=("GNU GPL v3.0")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/chunkio/main/chunkio/chunkio_bytes_reader.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/chunkio/main/chunkio/chunkio_lines_reader.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/chunkio/main/chunkio/chunkio_writer.hh")

sha512sums=(
	"cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e"
	"cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e"
	"cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e")

package() {
	echo "CHUNKIO : The Performant I/O Library"
	mkdir -p "${pkgdir}/usr/include/openutils/chunkio"
	cp "${srcdir}/chunkio_bytes_reader.hh" "${pkgdir}/usr/include/openutils/chunkio/chunkio_bytes_reader.hh"
	cp "${srcdir}/chunkio_lines_reader.hh" "${pkgdir}/usr/include/openutils/chunkio/chunkio_lines_reader.hh"
	cp "${srcdir}/chunkio_writer.hh" "${pkgdir}/usr/include/openutils/chunkio/chunkio_writer.hh"
	echo "Done!"
}
