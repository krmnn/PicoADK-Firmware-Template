# PicoADK - Audio Development Kit Firmware

## Development

The pipeline will trigger a full build on Push or Pull Request.

### Releasing

The pipeline will trigger a new release build on following tagging scheme:

```bash
git tag -a v1.0.0 -m "Release v1.0.0"
git push origin v1.0.0
```